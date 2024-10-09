#include<stdio.h>

typedef struct Node{
	int transition[5];
	}Node;
	
Node node[10];	

// e_closure() find and store e-closures to e_arr
int e_arr[10];

// intermediate e-closure calculated are stored in e_sub_arr
int e_sub_arr[10];

// contains the alphabets a,b,c......
char alphabets[10];
	

// map characters to an index value a-1, b-2 .....
int map(char a){

	if( a =='e' )
		return 0;	
	int i;
	i=a-96;
	return i;
}

int is_unique(int *arr, int count, int value);

// find e-closure of node e and store the result(indexes) in res[]
int e_closure(int e, int res[]){
	int count=0, i;
	res[count++] = e; // e closure contain itself
	while(node[e].transition[ map('e') ] !=-1 ){// check if there is an e transition
			i = node[e].transition[ map('e') ]; // return index of next node
			res[count++] = i;
			e = i;// set new node as current node 
	}
	return count;
}

int get_transition(int e,char a){
	if(node[e].transition[ map(a) ] !=-1 ){// check if there is the req transition
			int i = node[e].transition[ map(a) ]; // return index of next node
			return i;
	}
	return -1;
}

int is_unique(int *arr, int count, int value) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == value) return 0; // Not unique
    }
    return 1; // Unique
}

void perform(int n, int alpha) {
    for (int i = 0; i < n; i++) {
        int c = e_closure(i, e_arr); // Finding e-closure
        
        // Finding transitions for each alphabet
        for (int k = 0; k < alpha; k++) {    
            int r[50], cnt = 0;

            // Collect all transitions for current states
            for (int j = 0; j < c; j++) {
                int flag = get_transition(e_arr[j], alphabets[k]);
                if (flag != -1) { // Valid transition
                    r[cnt++] = flag; // Store reachable states
                }
            }

            int copy[50], count = 0; // For storing unique states
            for (int w = 0; w < cnt; w++) {
                // Only include unique states from the direct transitions
                if (is_unique(copy, count, r[w])) {
                    copy[count++] = r[w];
                }
            }

            // Collect e-closure for each unique state reached
            int final_states[50], final_count = 0;
            for (int w = 0; w < count; w++) {
                int b = e_closure(copy[w], e_sub_arr);
                for (int q = 0; q < b; q++) {
                    if (is_unique(final_states, final_count, e_sub_arr[q])) {
                        final_states[final_count++] = e_sub_arr[q]; // Add unique state
                    }
                }
            }

            // Print the final unique states after closure
            printf("State -> %d for alphabet %c >> { ", i, alphabets[k]);
            for (int p = 0; p < final_count; p++) {
                printf(" %d", final_states[p]);
            }
            printf(" }\n");
        }
    }
}

	
int main(){
	/*variables in main()
	 * 	INTEGERS
	 * n - no of nodes
	 * t - no of transitions
	 * a - no of alphabets 
	 *  -1 # indicates No transition for that input alphabet
	 * */
	int n,t,a,state1,state2,i,j;
	char alpha;

	printf("Enter the no of nodes :\n");
	scanf("%d",&n);
	printf("Enter the no of alphabets: \n");
	scanf("%d",&a);
	for(i=0;i<a;i++)
		scanf(" %c",&alphabets[i]);
		
	for(i=0;i<n;i++){
		for(j=0;j<a+1;j++)// for initializing with no transition, a+1 for including epsilon
			node[i].transition[j] = -1;
			
	}
	printf("Enter the no of transitions: \n");
	scanf("%d", &t);
	printf("Enter the state table:>>STATE ALPHABET STATE");
	for(i=0;i<t;i++){
		scanf("%d	%c	%d",&state1,&alpha,&state2);
		node[state1].transition[ map(alpha) ] = state2;
	}
	perform(n,a);

}

