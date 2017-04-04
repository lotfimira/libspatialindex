#include <iostream>
#include <spatialindex/capi/sidx_api.h>
#include <spatialindex/capi/sidx_impl.h>
#include <spatialindex/capi/sidx_config.h>

using namespace std;
using namespace SpatialIndex;

// function to create a new spatial index
Index* createIndex()
{
	// create a property set with default values.
	// see utility.cc for all defaults  http://libspatialindex.github.io/doxygen/Utility_8cc_source.html#l00031
	Tools::PropertySet* ps = GetDefaults();
	Tools::Variant var;

	// set index type to R*-Tree
	var.m_varType = Tools::VT_ULONG;
	var.m_val.ulVal = RT_RTree;
	ps->setProperty("IndexType", var);

	// Set index to store in memory (default is disk)
	var.m_varType = Tools::VT_ULONG;
	var.m_val.ulVal = RT_Memory;
	ps->setProperty("IndexStorageType", var);

	// initalise index
	Index* idx = new Index(*ps);
	delete ps;

	// check index is ok
	if (!idx->index().isIndexValid())
		throw "Failed to create valid index";
	else
		cout << "created index" << endl;

	return idx;
}


int main(int argc, char* argv[])
{
	// initalise Indexpointer
	Index* idx = createIndex();

}