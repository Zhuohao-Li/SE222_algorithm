#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

void bubbleSort(int a[], int p, int r) {
  for (int i = p; i < r; i++) {
    for (int j = i + 1; j <= r; j++) {
      if (a[j] < a[i]) swap(a[i], a[j]);
    }
  }
}  // bubblesort(), can produce a list from small to large

int Partition(int a[], int p, int r, int val) {
  int pos;
  for (int q = p; q <= r; q++) {
    if (a[q] == val) {
      pos = q;
      break;
    }
  }
  swap(a[p], a[pos]);

  int i = p, j = r + 1, x = a[p];
  while (1) {
    while (a[++i] < x && i < r)
      ;
    while (a[--j] > x)
      ;
    if (i >= j) break;
    swap(a[i], a[j]);
  }
  a[p] = a[j];
  a[j] = x;
  return j;
}

int Select(int a[], int p, int r, int k) {  // larger k,  larger value
  if (r - p < 75) {
    bubbleSort(a, p, r);  // if not many data, just do sort()
    return a[p + k - 1];  // after it, a[n] is sorted, a[0] is the smallest,
    // for 10.txt, Select(a, 0, 9, 10) is the biggest,  Select(a, 0, 9, 1) is
    // the smallest Select(a, 0, 9, 5) is the mid-one
  }
  // divided [n/5] groups, each group has 1-5 items
  for (int i = 0; i <= (r - p) / 5; i++)
  // exchange every mid value with the head items in a[0:(r-p)/5]
  {
    int s = p + 5 * i, t = s + 4;
    for (int j = 0; j < 3; j++) {
      for (int n = s; n < t - j; n++) {
        if (a[n] > a[n + 1]) swap(a[n], a[n + 1]);
      }
      // bubblesort for 3 times, then we get 3 largest values in each group
    }
    swap(a[p + i],
         a[s + 2]);  // exchange every mid items pf each group to the front
  }
  // get the mid value of mid values ( from a[p] : a[p+(r - p) / 5])
  int x = Select(a, p, p + (r - p) / 5, (r - p + 5) / 10);  //求中位数的中位数
  /*
  (r-p+5)/10 = (p+(r+p)/5-p+1)/2
  */
  int i = Partition(a, p, r, x), j = i - p + 1;
  if (k <= j)
    return Select(a, p, i, k);
  else
    return Select(a, i + 1, r, k - j);
}

void result(int n) {
  switch (n) {
    case 1: {
      ifstream fin;
      fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/10.txt");

      int i = 0;
      int data[10];
      for (i = 0; i < 10; ++i) {
        fin >> data[i];
      }
      cout << Select(data, 0, 9, 5) << endl;
      break;
    }

    case 2: {
      ifstream fin;
      fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/100.txt");

      int i = 0;
      int data[100];
      for (i = 0; i < 100; ++i) {
        fin >> data[i];
      }
      cout << Select(data, 0, 99, 50) << endl;
      break;
    }

    case 3: {
      ifstream fin;
      fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/1000.txt");

      int i = 0;
      int data[1000];
      for (i = 0; i < 1000; ++i) {
        fin >> data[i];
      }
      cout << Select(data, 0, 999, 501) << endl;
      break;
    }

    case 4: {
      ifstream fin;
      fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/10000.txt");

      int i = 0;
      int data[10000];
      for (i = 0; i < 10000; ++i) {
        fin >> data[i];
      }
      cout << Select(data, 0, 9999, 5000) << endl;
      break;
    }

    case 5: {
      ifstream fin;
      fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/100000.txt");

      int i = 0;
      int data[100000];
      for (i = 0; i < 100000; ++i) {
        fin >> data[i];
      }
      cout << Select(data, 0, 99999, 50000) << endl;
      break;
    }

    case 6: {
      ifstream fin;
      fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/1000000.txt");

      int i = 0;
      int data[1000000];
      for (i = 0; i < 1000000; ++i) {
        fin >> data[i];
      }
      cout << Select(data, 0, 999999, 500001) << endl;
      fin.close();
      break;
    }
  }
}

int main() {
  int n = 0;
  cin >> n;
  auto start = std::chrono::steady_clock::now();
  result(n);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::micro> elapsed =
      end - start;  // std::micro 表示以微秒为时间单位
  std::cout << "time: " << elapsed.count() << "us" << std::endl;
}
