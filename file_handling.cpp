#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 10;
int array1[MAX] = {10, 20, 30, 40, 50, 78, 45, 56, 96, 12};
int array2[MAX];
int main()
{
    ofstream os;
    os.open("sample.txt", ios::out);
    if (!os)
    {
        cerr << "Could not open output file\n";
        exit(1);
    }
    cout << "Writing the contents to the file...\n\n";
    os.write((char *)&array1, sizeof(array1));
    // for (int i = 0; i < MAX; i++)
    // {
    //     os.put(array1[i]);
    // }
    if (!os)
    {
        cerr << "Could not write to file\n";
        exit(1);
    }
    os.close();
    ifstream in;
    in.open("sample.txt", ios::in);
    if (!in)
    {
        cerr << "Could not open input file\n";
        exit(1);
    }
    cout << "Reading the contents from the file ...\n";

    in.read((char *)&array2, sizeof(array2));
    // for (int i = 0; i < MAX; i++)
    // {
    //     array2[i] = in.get();
    // }

    if (!in)
    {
        cerr << "Could not read from file\n";
        exit(1);
    }
    in.close();
    for (int j = 0; j < MAX; j++)
        cout << " " << array2[j];

    return 0;
}