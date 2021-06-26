#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int writeMatr(string file, int n)
{
    ofstream ofE(file + string("E.txt"), ofstream::out);
    ofstream ofV(file + string("V.txt"), ofstream::out);
    ofstream ofW(file + string("W.txt"), ofstream::out);

    int a = 2, b = 50;
    int tmp;
    vector<vector<int>> martE;
    vector<vector<int>> martV;
    vector<vector<int>> martW;
    martE.reserve(n);
    martV.reserve(n);
    martW.reserve(n);
    for (int i = 0; i < n; i++)
    {
        martE.push_back(vector<int>());
        martV.push_back(vector<int>());
        martW.push_back(vector<int>());
        martE.at(i).reserve(n);
        martV.at(i).reserve(n);
        martW.at(i).reserve(n);
        for (int j = 0; j < n; j++)
        {

            tmp = rand();
            if (tmp > static_cast<int>(RAND_MAX*0.30))
            {
                martE.at(i).push_back(1);
            }
            else
            {
                martE.at(i).push_back(0);
            }
            martV.at(i).push_back((b - a)*(static_cast<float>(rand())/static_cast<float>(RAND_MAX)) + a);
            martW.at(i).push_back((b - a)*(static_cast<float>(rand())/static_cast<float>(RAND_MAX)) + a);
            ofE << martE.at(i).at(j) << " ";
            ofV << martV.at(i).at(j) << " ";
            ofW << martW.at(i).at(j) << " ";
        }
        ofE << endl;
        ofV << endl;
        ofW << endl;
    }

    ofE.close();
    ofV.close();
    ofW.close();

    return 0;
}

void writeReqCon(string file, int n)
{
    ofstream ofR(file + string("Reqs.txt"), ofstream::out);
    ofstream ofC(file + string("Cons.txt", ofstream::out));
    int a = 2, b = 50;
    int tmp1 = a, tmp2 = 12;
    int n1 = 1, n2 = 5;
    vector<vector<int>> reqs;
    vector<int> cons;

    reqs.reserve(n);
    cons.reserve(n);

    for (int i = 0; i < n; i++)
    {
        reqs.push_back(vector<int>());
        reqs.at(i).reserve(n);
        reqs.at(i).push_back((tmp2 - tmp1)*(static_cast<float>(rand())/static_cast<float>(RAND_MAX)) + tmp1);
        if (i == 0)
        {
            reqs.at(i).back() = 0;
        }
        ofR << reqs.at(i).back() << " ";
        tmp1 = reqs.at(i).back();
        tmp2 = tmp1 + 10;
        reqs.at(i).push_back((b - a)*(static_cast<float>(rand())/static_cast<float>(RAND_MAX)) + a);
        ofR << reqs.at(i).back() << endl;
        cons.push_back((n2 - n1)*(static_cast<float>(rand())/static_cast<float>(RAND_MAX)) + n1);
        ofC << cons.back() << endl;
    }

    ofR.close();
    ofC.close();
}

int main()
{
    srand(time(NULL));

    int startCount = 1;
    int copyes = 10;
    int dim = 10;

    char num[4];
    string file("data");
    string numFile;

    for (int i = 0; i < copyes; i++)
    {
        sprintf(num, "%d", startCount++);
        numFile = file + string(num);
        writeMatr(numFile, dim);
        writeReqCon(numFile, dim);
    }
    cout << "done" << endl;

    return 0;
}
