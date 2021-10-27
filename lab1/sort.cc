#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

void Merge(int *a, int p, int q, int r) {
  int n1 = q - p + 1;  //左部分的的元素个数
  int n2 = r - q;      //同上
  int i, j, k;
  int *L = new int[n1 + 1];
  int *R = new int[n2 + 1];
  for (i = 0; i < n1; i++) L[i] = a[p + i];
  for (j = 0; j < n2; j++) R[j] = a[q + j + 1];
  L[n1] = 11111111;
  R[n2] = 11111111;
  // 数组L从0~n1-1存放，第n1个存放int型所能表示的最大数，即认为正无穷，这是为了
  //处理合并时，比如当数组L中的n1个元素已经全部按顺序存进数组a中，只剩下数组R的
  //部分元素，这时因为R中剩下的元素全部小于11111111,则执行else语句，直接将剩下的
  //元素拷贝进a中。
  for (i = 0, j = 0, k = p; k <= r; k++) {
    if (L[i] <= R[j])
      a[k] = L[i++];
    else
      a[k] = R[j++];
  }

  delete[] L;
  delete[] R;
}

void MergeSort(int *a, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
  }
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
      MergeSort(data, 0, 9);
      cout << data[4] << endl;
      // for (i = 0; i < 10; i++) cout << data[i] << " ";
      // cout << endl;

      fin.close();
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
      MergeSort(data, 0, 99);
      cout << data[49] << endl;
      // for (i = 0; i < 100; i++) cout << data[i] << " ";
       //cout << endl;

      fin.close();
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
      MergeSort(data, 0, 999);
      cout << data[499] << endl;
      // for (i = 0; i < 10; i++) cout << data[i] << " ";
      // cout << endl;

      fin.close();
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
      MergeSort(data, 0, 9999);
      cout << data[4999] << endl;
      // for (i = 0; i < 10; i++) cout << data[i] << " ";
      // cout << endl;

      fin.close();
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
      MergeSort(data, 0, 99999);
      cout << data[49999] << endl;
      // for (i = 0; i < 10; i++) cout << data[i] << " ";
      // cout << endl;

      fin.close();
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
      MergeSort(data, 0, 999999);
      cout << data[499999] << endl;
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
