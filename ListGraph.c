#include <stdio.h>
#include <stdlib.h>

#include "ListGraph.h"
#include "LinkedList.h"

list_graph_t*
lg_create(int nodes)
{
	list_graph_t *graphlist = malloc(sizeof(*graphlist));

	graphlist->nodes = nodes;
	graphlist->neighbors = malloc(nodes * sizeof(*(graphlist->neighbors)));
	for(int i = 0; i < nodes; i++)
		graphlist->neighbors[i] = ll_create(sizeof(int));

	return graphlist;
}

void
lg_add_edge(list_graph_t* graph, int src, int dest, int weight)
{
	if(graph == NULL || graph->neighbors == NULL)
		return;

	ll_add_nth_node(graph->neighbors[src], graph->neighbors[src]->size, &dest, weight);
}

int
lg_has_edge(list_graph_t* graph, int src, int dest)
{
	if(graph == NULL || graph->neighbors == NULL)
		return 0;

	unsigned int ok = 0;
	ll_node_t *nod_dest = graph->neighbors[src]->head;
	while(nod_dest != NULL) {
		int nod = (*(int*)nod_dest->data);
		if(nod == dest) {
			ok = 1;
			break;
		}
		nod_dest = nod_dest->next;
	}

	if(ok == 0)
		return 0;
	return 1;
}

linked_list_t*
lg_get_neighbours(list_graph_t* graph, int node)
{
	if(graph == NULL || graph->neighbors == NULL)
		return NULL;

	return graph->neighbors[node];
}

void
lg_remove_edge(list_graph_t* graph, int src, int dest)
{
	if(graph == NULL || graph->neighbors == NULL)
		return;

	ll_node_t *nod_dest = graph->neighbors[src]->head;
	int i = 0;
	while(nod_dest != NULL) {
		int nod = (*(int*)nod_dest->data);
		if(nod == dest) {
			ll_node_t *del = ll_remove_nth_node(graph->neighbors[src], i);
			free(del->data);
			free(del);
			break;
		}
		i++;
		nod_dest = nod_dest->next;
	}
}

void
lg_free(list_graph_t* graph)
{
	if(graph == NULL)
		return;
	if(graph->neighbors == NULL) {
		free(graph);
		return;
	}
	int i = 0;
	linked_list_t *neighbor = NULL;
	while(i < graph->nodes) {
		neighbor = graph->neighbors[i];
		ll_free(&neighbor);
		i++;
	}
	free(graph->neighbors);
	free(graph);
}
