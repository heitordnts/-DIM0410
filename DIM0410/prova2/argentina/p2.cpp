#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

struct jogador {
    string nome;
    int at;
    int df;
};

bool ordem (struct jogador jog1, struct jogador jog2){
    if (jog1.at > jog2.at)
        return true;
    else if (jog1.at < jog2.at)
        return false;

    if (jog1.df < jog2.df)
        return true;
    else if (jog1.df > jog2.df)
        return false;
    
    if (lexicographical_compare(jog1.nome.begin(),jog1.nome.end(),jog2.nome.begin(),jog2.nome.end()))
        return true;
    else
        return false;
}

bool ordem2 (struct jogador jog1, struct jogador jog2){
    if (lexicographical_compare(jog1.nome.begin(),jog1.nome.end(),jog2.nome.begin(),jog2.nome.end()))
        return true;
    else
        return false;
}



int main(){
    int t, at, df, cs = 1;
    string nome;
    struct jogador jog;
    struct jogador time[10];
    
    cin >> t;

    for (int j = 0; j < t; j++){
        for (int i = 0; i < 10; i++){
            cin >> nome;
            cin >> at;
            cin >> df;

            jog.nome = nome;
            jog.at = at;
            jog.df = df;

            time[i] = jog;
        }

        sort(time, time+10, ordem);

        sort(time, time+5, ordem2);
        sort(time+5, time+10, ordem2);
        
        cout << "Case " << cs << ":" << endl;
        cout << "(";
        for (int i = 0; i < 5; i++){
            if (i != 0)
                cout << ", ";
            //cout << time[i].nome << " " << time[i].at << " " << time[i].df;
            cout << time[i].nome;
        }
        cout << ")\n(";
        for (int i = 5; i < 10; i++){
             if (i != 5)
                cout << ", ";
            //cout << time[i].nome << " " << time[i].at << " " << time[i].df;
            cout << time[i].nome;
        }
        cout << ")" << endl;

        cs++;
    }


    return 0;
}
