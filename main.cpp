#include <bits/stdc++.h>

using namespace std;




void afficherA(vector<vector<float>> tab){
    for(int i=0; i<tab[0].size(); i++){
        for(int j=0; j<tab[0].size(); j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}


void afficherB(vector<float> tab){
    for(int i=0; i<tab.size(); i++){
        cout<<tab[i];
        cout<<endl;
    }
}


int creationSystem(vector<vector<float>> &A,vector<float> &b){
    vector<float> tmp;
    int n;
    float m;
    cout<<"Entrez le nombre d'inconnu du System à resoudre :";
    cin >> n;
    cout<<"Matrice A :\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Entrez l'element ["<<i+1<<"]["<<j+1<<"] de al matrice A :";
            cin>>m;
            tmp.push_back(m);
        }
        A.push_back(tmp);
        tmp.clear();
    }
    cout<<"Matrice b :\n";
    for(int i=0; i<n; i++){
        cout<<"Entrez l'element ["<<i+1<<"][0] de la matrice b :";
        cin>>m;
        b.push_back(m);
    }
    return n;
}

void decomposition(vector<vector<float>> &a,vector<vector<float>> &l,vector<vector<float>> &u){
    //l.clear();u.clear();
    for(int i=0; i<a[0].size(); i++)
        for(int j=0; j<a[0].size(); j++)
            u[i][j]=a[i][j];

    int n=u[0].size();
    float m;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            l[j][i]=(u[j][i]/u[i][i]);
            for(int k=i+1; k<n; k++){
                u[j][k]=u[j][k]-(l[j][i]*u[i][k]);
            }
        }
    }

    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            if(i>j) u[i][j]=0;
            if(i==j) l[i][j]=1;
        }
    }

    cout << "La matrice L est :"<<endl;
    for (int i = 0; i < l[0].size(); i++) {
        for (int j = 0; j < l[0].size(); j++) {
            cout<<l[i][j]<<" ";
        }
        cout << endl;
    }
    cout << "La matrice U est : "<<endl;
    for (int i = 0; i < u[0].size(); i++) {
        for (int j = 0; j < u[0].size(); j++) {
            cout<<u[i][j]<<" ";
        }
        cout << endl;
    }

}



void resolution(vector<vector<float>> s){

    vector<float> solution;
    int n=s[0].size();
    float m;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            m=(s[j][i]/s[i][i]);
            for(int k=i+1; k<n; k++){
                s[j][k]=s[j][k]-(m*s[i][k]);
            }
        }
    }
    for(int i=0;i<n-1; i++){
        for(int j=0; j<n; j++){
            if(i>j) s[i][j]=0;
        }
    }
    n--;
    float sol[n];

    sol[n-1]=s[n-1][n]/s[n-1][n-1];
    s[n-1][n]=s[n-1][n-1]=0;
    int p;

    for(int i=1; i<n; i++){
        p=i;
        for(int j=2; j<=n; j++){
            s[n-j][n-i]*=sol[n-i];
            s[n-j][n]-=s[n-j][n-i];
            s[n-j][n-i]=0;
            p++;
        }
        m=s[n-(i+1)][n]/s[n-(i+1)][n-(i+1)];
        sol[n-(i+1)]=m;
    }

    for(int i=0; i<n; i++){
        cout<<"x"<<i+1<<"="<<sol[i]<<endl;
    }

}


int main(){

    int n=0,a;
    vector<vector<float>> A;
    vector<vector<float>> L;
    vector<vector<float>> U;
    vector<vector<float>> S;
    vector<float> b,tmp;

    int num = creationSystem(A,b);

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            tmp.push_back(0);
        }
        L.push_back(tmp);
        U.push_back(tmp);
        tmp.clear();
    }
    system("clear");
    cout<<"Affichage des matrices \n"<<"Matrice A :\n";
    afficherA(A);
    cout<<"\nMatrice b :\n";
    afficherB(b);

    cout<<"\nDecomposition LU de la matrice A\n";
    decomposition(A,L,U);
    

    tmp.clear();
    for(int i=0; i<A[0].size(); i++){
        for(int j=0; j<A[0].size(); j++){
            tmp.push_back(A[i][j]);
        }
        tmp.push_back(b[i]);
        S.push_back(tmp);
        tmp.clear();
    }

    cout<<"\nSolution du systeme S "<<endl;

    resolution(S);


    return 0;
}
