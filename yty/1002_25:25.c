#include <stdio.h>
#include <stdlib.h>

//Linked list for Polynomial 
typedef struct Polynomial {
	float coef;
	int expn;
	struct Polynomial * next;
} *Polyn, Polynomial;

//Insert a term
void Insert(Polyn p,Polyn h){
	if(p->coef == 0) 
		free(p);
	else {
		Polyn q1,q2;
        q1=h;
    	q2=h->next;
    	//find the correct place 
    	while (q2 && p->expn < q2->expn) {
    		q1 = q2;
    		q2 = q2->next;
    	}
    	//insert the term
    	if (q2&& p->expn == q2->expn) {
    		q2->coef += p->coef;
    		free(p);
    		if (!q2->coef) {
    			q1->next = q2->next;
    			free(q2);
    		}
    	}
    	else {
    		p->next = q2;
    		q1->next = p;
    	}
    }
}

//Create polynomial with m terms
Polyn CreatePolyn(Polyn head, int m) {
	int i;
	Polyn p;
	p = head = (Polyn)malloc(sizeof(struct Polynomial));
	head->next = NULL;
	for (i = 0; i < m; ++i) {
		p = (Polyn)malloc(sizeof(struct Polynomial));
		scanf("%d %f", &p->expn, &p->coef);
		Insert(p, head);
	}
	return head;
}

void DestroyPolyn(Polyn p) {
	Polyn q1, q2;
	q1 = p->next;
	q2 = q1->next;
	while (q1->next) {
		free(q1);
		q1 = q2;
		q2 = q2->next;
	}
}

void PrintPolyn(Polyn p) {
	Polyn q = p->next;
	int flag = 1;
	if (!q) {
		putchar('0');
		printf("\n");
		return;
	}
	//print the number of terms
	while (q) {
		q = q->next;
		flag++;
	}
	printf("%d", flag-1);
	//print the poly
	q = p->next;
	while (q) {
		printf(" %d %.1f", q->expn, q->coef);
		q = q->next;
	}
	printf("\n");
}

//returns 1 if a > b
//returns -1 if a < b
//returns 0 if a == b
int compare(Polyn a, Polyn b) {
	if (a && b) {
		if (!b || a->expn > b->expn)
			return 1;
		else if (!a || a->expn < b->expn)
			return -1;
		else return 0;
	}
	else if (!a&&b)
		return -1;
	else 
		return 1;
}

Polyn AddPolyn(Polyn pa, Polyn pb) {
	Polyn qa = pa->next;
	Polyn qb = pb->next;
	Polyn headc, hc, qc;
	hc = (Polyn)malloc(sizeof(struct Polynomial));
	hc->next = NULL;
	headc=hc;
	while (qa || qb) {
		qc = (Polyn)malloc(sizeof(struct Polynomial));
		switch(compare(qa, qb)) {
			case 1:
			{
				qc->coef = qa->coef;
				qc->expn = qa->expn;
				qa = qa->next;
				break;
			}
			case 0:
			{
				qc->coef = qa->coef+qb->coef;
				qc->expn = qa->expn;
				qa = qa->next;
				qb = qb->next;
				break;
			}
			case -1:
			{
				qc->coef = qb->coef;
				qc->expn = qb->expn;
				qb = qb->next;
				break;
			}
		}
		if (qc->coef != 0) {
			qc->next = hc->next;
			hc->next = qc;
			hc = qc;
		}
	else 
		free (qc);
	}
	return headc;
}

int main(int argc, char const *argv[])
{
	int m, n, a = 1;
	double x;
	int flag;
	Polyn pa = 0, pb = 0, pc = 0;
	scanf("%d", &m);
	pa = CreatePolyn(pa, m);
	scanf("%d", &n);
	pb = CreatePolyn(pb, n);
	pc = AddPolyn(pa, pb);
	printf("");
	PrintPolyn(pc);
	
	return 0;
}
