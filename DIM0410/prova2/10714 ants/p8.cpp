#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

#define MIN(x,y) (x < y? x : y)

#define MAX(x,y) (x > y? x : y)

int main(){
    int cs, cm, nf, l;
    int menorAnt, menorAtual, maior;
    

    cin >> cs;

    for (int c = 0; c < cs; c++){
        cin >> cm >> nf;
        int vf[nf];
		int vf2[nf];
        for (int c2 = 0; c2 < nf; c2++){
            cin >> l;
            vf[c2] = MIN(l,cm-l);
			vf2[c2] = l;
        }
		sort(vf2,vf2+nf);	
        sort(vf, vf+nf);
		int menor = vf[nf-1];
		int maior = MAX(vf2[nf-1],cm - vf2[0]); 
		cout << menor << " " << maior << endl;
    }
    


    return 0;
}
