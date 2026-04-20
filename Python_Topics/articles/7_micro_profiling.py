from collections import Counter 
import objgraph 
def graph_references(*objects):
	objgraph.show_refs( objects, filename='show_refs.png', \
	refcounts=True) 
	objgraph.show_backrefs( objects, filename='show_backrefs.png',\
	refcounts=True) 
quote = """Hello world"""
graph_references(quote)
