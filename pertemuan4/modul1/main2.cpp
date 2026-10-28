#include<iostream>
using namespace std;

void tambahData(int* arr, int& n , int nilai)
{
    int* newArr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[n] = nilai;
    delete[] arr;
    arr = newArr;
    n++;
}

void hapusData(int* arr, int& n, int index)
{
    if (n== 0)
    {
        cout<<"array kosong , tidak ada yang di hapus"<<endl;
        return;
    }
    if (index < 0 || index >= n)
    {
        cout<<"indeks tidak valid"<<endl;
        return;
    }
    if (n ==1)
    {
        delete[] arr;
        arr = nullptr;
        n = 0;
        cout<<"data pada indeks"<<index<<" berhasil dihapus"<<endl;
        return;
    }
    int* newArr = new int[n - 1];
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != index)
            {
                newArr[j] = arr[i];
                j++;
            }
        }
    }
    delete[] arr;
    arr = newArr;
    n--;
    cout<<"data pada indeks"<<index<<" berhasil dihapus"<<endl;
    }

    int cariData(int* arr, int n, int nilai)
    {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == nilai)
        {
            return i;
        }
    }

    return -1;
    }

void tampilkanData(int* arr, int n)
{
    if(n == 0 || arr == nullptr)
    {
        cout<<"array kosong"<<endl;
        return;
    }
    cout<<"isi aarray : ";
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    system("cls");
    int n =0;
    int* arr = nullptr;

    tambahData(arr, n, 10);
    tambahData(arr, n, 20);
    tambahData(arr, n, 30);
    tambahData(arr, n, 40);
    tampilkanData(arr, n);

    int cari = 30;
    int pos = cariData(arr, n, cari);
    if (pos != -1) cout << "Nilai " << cari << " ditemukan pada indeks " << pos << endl;
    else cout << "Nilai " << cari << " tidak ditemukan\n";

    hapusData(arr, n, 1);               // hapus indeks 1 (nilai 20)
    tampilkanData(arr, n);              // 10 30 40

    cari = 20;
    pos = cariData(arr, n, cari);
    if (pos != -1) cout << "Nilai " << cari << " ditemukan pada indeks " << pos << endl;
    else cout << "Nilai " << cari << " tidak ditemukan\n";

    delete[] arr;                       // bebaskan memori terakhir
    return 0;
}