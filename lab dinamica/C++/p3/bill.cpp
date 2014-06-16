#include <fstream>
#include <iostream>
#include <vector>

#define MOD 9901
#define MAX_TERM 19

int countSols(int N, int R) {
    std::vector< std::vector<int> > count(N + 1, std::vector<int>(100, 0));

    //count[i][j] = cate sume exista care au i termeni si care dau restul j la
    //impartirea prin 100

    //TODO Initializati linia 1 a dinamicii
    for (int t = 0; t <= MAX_TERM; ++t) {
        count[1][t]=1;

    }

    //TODO Calculati liniile 2..N ale dinamicii
    //Hint: Pentru a determina numarul de sume cu i termeni puteti considera ca
    //mai adaugati un termen la sumele care au (i - 1) termeni
    for (int i = 2; i <= N; i++) {

     for(int r=0;r<100;r++)
       for(int t=0;t<=MAX_TERM;t++)
        { int x=0;
            if(r-t>=0) x=r-t;
             else x =100-(t-r);
             count[i][r]=(count[i][r]+count[i-1][x]) % MOD;
        }

    }

    return count[N][R];
}

//Inmulteste matricele A si B. Rezultatul este returnat in matricea B.
//Operatiile sunt modulo MOD.
inline void multiplyMatrix(
    std::vector< std::vector<int> >& A,
    std::vector< std::vector<int> >& B
) {
    const size_t N = A.size();
    const size_t M = B[0].size();
    const size_t K = A[0].size();

    std::vector< std::vector<int> > Res(N, std::vector<int>(M, 0));

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            for (size_t k = 0; k < K; ++k) {
                Res[i][j] = (Res[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    B.swap(Res);
}

//Inmulteste matricea A cu vectorul v. Rezultatul este returnat in vectorul v.
//Operatiile sunt modulo MOD
inline void multiplyMatrixVector(
    std::vector< std::vector<int> >& A,
    std::vector<int>& v
) {
    const size_t N = A.size();
    const size_t M = v.size();

    std::vector<int> vRes(N, 0);

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            vRes[i] = (vRes[i] + A[i][j] * v[j]) % MOD;
        }
    }

    v.swap(vRes);
}

//Ridica la puterea p matricea patratica A. Matricea finala este returnata in A.
//Operatiile sunt modulo MOD.
inline void logPowMatrix(std::vector< std::vector<int> >& A, int p) {
    std::vector< std::vector<int> > Res(A.size(),std::vector<int>(A.size(), 0));

    for (size_t i = 0; i < Res.size(); ++i) {
        Res[i][i] = 1;
    }

    //TODO
     //Res = std::pow(A, p);


    A.swap(Res);
}

int countSolsLog(int N, int R) {
    std::vector< std::vector<int> > A(100, std::vector<int>(100, 0));
    std::vector<int> count(100, 0);

    //TODO Initializati count.
    //count[i] = cate sume cu un termen dau restul i la impartirea prin 100
    for (int t = 0; t <= MAX_TERM; ++t) {
    count[t]=1;
    }

    //TODO Initializati matricea A
    //Hint: vreti ca (A * count) sa fie un vector in care elementul i sa
    //reprezinte numarul de moduri in care putem construi secvente cu N termeni
    //a caror suma sa dea restul i la impartirea prin 100
  for(int rest=0;rest<100;rest++)
   for(int t=0;t<=MAX_TERM;t++)
   {
       int rp=(rest+100-t)%100;
       A[rest][rp]++;
   }

    //TODO Ridicati matricea A la putere folosind functia logPowMatrix
    //Faceti acest lucru dupa ce ati completat functia logPowMatrix


    multiplyMatrixVector(A, count);

    return count[R];
}

struct Input {
    int N, R;

    Input(int N, int R) {
        this->N = N;
        this->R = R;
    }
};

int main() {
    std::vector<Input> inputs;

    inputs.push_back(Input(3, 2)); // 6
    inputs.push_back(Input(123, 4)); // 2490
    inputs.push_back(Input(2014, 3)); // 244

    for (size_t i = 0; i < inputs.size(); ++i) {
        std::cout << "N = " << inputs[i].N << ", ";
        std::cout << "R = " << inputs[i].R << " -> ";
        std::cout << countSols(inputs[i].N, inputs[i].R);
        std::cout << " ";
        std::cout << countSolsLog(inputs[i].N, inputs[i].R);
        std::cout << std::endl;
    }

    return 0;
}
