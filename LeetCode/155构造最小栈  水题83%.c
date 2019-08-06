typedef struct linkedList {
	int data;
	struct linkedList *next;
} list;

typedef struct {
	list *head;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack *stack = malloc(sizeof(MinStack));
	stack->head = malloc(sizeof(list));
	stack->head->data = 0x7FFFFFFF;
	stack->head->next = NULL;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
	if(!obj)return;
	list *p = malloc(sizeof(list));
	p->data = x;
	p->next = obj->head->next;
	obj->head->next = p;
	if(obj->head->data>x)obj->head->data = x;
}

void minStackPop(MinStack* obj) {
	if(!obj)return;
	list *dead = obj->head->next;
	if(dead) {
		obj->head->next = dead->next;
		if(dead->data==obj->head->data) {
			obj->head->data = 0x7FFFFFFF;
			for(list *p = obj->head->next; p; p=p->next) {
				if(obj->head->data>p->data) {
					obj->head->data = p->data;
				}
			}
		}
		free(dead);
	}
}

int minStackTop(MinStack* obj) {
	if(!obj)return;
	if(obj->head->next)return obj->head->next->data;
	else return -1;
}

int minStackGetMin(MinStack* obj) {
	if(!obj)return -1;
	return obj->head->data;
}

void minStackFree(MinStack* obj) {
	if(!obj)return;
	list *dead = obj->head;
	while(dead){
		obj->head = dead->next;
		free(dead);
		dead = obj->head;
	}
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/