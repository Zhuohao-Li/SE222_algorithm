#include "bits/stdc++.h"

using namespace std;

int maxNum(int a, int b) { return (a > b) ? a : b; }

void insight(int *exist, int **val, int *w, int bagnum, int weight) {
  for (int i = bagnum; i > 0; i--) {
    if (val[i][weight] > val[i - 1][weight]) {
      exist[i] = 1;
      weight = weight - w[i];
    }
  }

  for (int j = 1; j <= bagnum; j++) cout << exist[j] << " ";
}

int maxVal(int **val, int *v, int *w, int bagnum, int weight) {
  int i, j;
  for (i = 0; i <= bagnum; i++) val[i][0] = 0;
  for (i = 0; i <= weight; i++) val[0][i] = 0;

  for (i = 1; i <= bagnum; i++) {
    for (j = 1; j <= weight; j++) {
      if (j < w[i])
        val[i][j] = val[i - 1][j];
      else
        val[i][j] = max(val[i - 1][j], val[i - 1][j - w[i]] + v[i]);
    }
  }
  return val[bagnum][weight];
}

long long maxVal2(long long **val, long long *v, long long *w, int bagnum,
                  long long weight) {
  int i, j;
  for (i = 0; i <= bagnum; i++) val[i][0] = 0;
  for (i = 0; i <= weight; i++) val[0][i] = 0;

  for (i = 1; i <= bagnum; i++) {
    for (j = 1; j <= weight; j++) {
      if (j < w[i])
        val[i][j] = val[i - 1][j];
      else
        val[i][j] = max(val[i - 1][j], val[i - 1][j - w[i]] + v[i]);
    }
  }

  return val[bagnum][weight];
}

void insight2(int *exist, long long **val, long long *w, int bagnum,
              long long weight) {
  for (int i = bagnum; i > 0; i--) {
    if (val[i][weight] > val[i - 1][weight]) {
      exist[i] = 1;
      weight = weight - w[i];
    }
  }

  for (int j = 1; j <= bagnum; j++) cout << exist[j] << " ";
}

int main() {
  int i, j;
  int num;
  cout << "which file do you want to check? print 1 if you want to check "
          "data1.dat, print 2 if you want to check data2.dat "
       << endl;
  cin >> num;
  ifstream fin;

  switch (num) {
    case 0: {
      int bagnum, weight;
      fin.open("/Users/edith_lzh/Desktop/c++/algorithm/lab2/test.dat");

      int l = 0;
      int data[3];
      int arr[3];
      for (l = 0; l < 6; l++) {
        if (l % 2 == 0) fin >> arr[l / 2];   // 1001 array, 1st is 0
        if (l % 2 == 1) fin >> data[l / 2];  // 1001 array, 1st is limit
      }
      fin.close();

      bagnum = arr[2];   // number of bags
      weight = data[0];  // limit

      int **val = new int *[bagnum + 1];  //这样定义二维数组，是为了方便传入
      val[0] = new int[(bagnum + 1) * (weight + 1)];
      for (i = 1; i <= bagnum; i++) val[i] = val[i - 1] + weight + 1;

      int *w = new int[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) w[i] = data[i];

      int *v = new int[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) v[i] = w[i];

      cout << maxVal(val, v, w, bagnum, weight) << endl;

      maxVal(val, v, w, bagnum, weight);

      int *exist = new int[bagnum]();  //为了查看我们选择了哪些包
      cout << "we get the bag num is:";
      insight(exist, val, w, bagnum, weight);
      cout << endl;
      break;
    }
    case 1: {
      int bagnum, weight;
      fin.open("/Users/edith_lzh/Desktop/c++/algorithm/lab2/data1.dat");

      int l = 0;
      int data[1001];
      int arr[1001];
      for (l = 0; l < 2002; l++) {
        if (l % 2 == 0) fin >> arr[l / 2];   // 1001 array, 1st is 0
        if (l % 2 == 1) fin >> data[l / 2];  // 1001 array, 1st is limit
      }
      fin.close();

      bagnum = arr[1000];  // number of bags
      weight = data[0];    // limit

      int **val = new int *[bagnum + 1];  //这样定义二维数组，是为了方便传入
      val[0] = new int[(bagnum + 1) * (weight + 1)];
      for (i = 1; i <= bagnum; i++) val[i] = val[i - 1] + weight + 1;

      int *w = new int[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) w[i] = data[i];

      int *v = new int[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) v[i] = w[i];

      cout << "max sum is:" << maxVal(val, v, w, bagnum, weight) << '\n';
      // auto start = std::chrono::steady_clock::now();
      // maxVal(val, v, w, bagnum, weight);
      int *exist = new int[bagnum]();  //为了查看我们选择了哪些包
      cout << "number we choose:";
      insight(exist, val, w, bagnum, weight);
      cout << endl;
      // auto end = std::chrono::steady_clock::now();
      // std::chrono::duration<double, std::milli> elapsed =
      //   end - start;  // std::micro 表示以微秒为时间单位
      // std::cout << "time: " << elapsed.count() << "ms" << std::endl;
      break;
    }
    case 2: {
      int bagnum;
      long long weight;
      ifstream fin;
      fin.open("/Users/edith_lzh/Desktop/c++/algorithm/lab2/data2.dat");
      int l = 0;
      long long data[4];
      int arr[4];
      // int all[6];
      for (l = 0; l < 8; l++) {
        if (l % 2 == 0) fin >> arr[l / 2];   // 4 array, 1st is 0
        if (l % 2 == 1) fin >> data[l / 2];  // 4 array, 1st is limit
      }
      fin.close();

      bagnum = arr[3];   // number of bags
      weight = data[0];  // limit is quite long long

      long long **val =
          new long long *[bagnum + 1];  //这样定义二维数组，是为了方便传入
      val[0] = new long long[(bagnum + 1) * (weight + 1)];
      for (i = 1; i <= bagnum; i++) val[i] = val[i - 1] + weight + 1;

      long long *w = new long long[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) w[i] = data[i];

      long long *v = new long long[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) v[i] = w[i];

      cout << "max sum is:" << maxVal2(val, v, w, bagnum, weight) << '\n';
      // auto start = std::chrono::steady_clock::now();
      // maxVal2(val, v, w, bagnum, weight);
      int *exist = new int[bagnum]();  //为了查看我们选择了哪些包
      cout << "number we choose:";
      insight2(exist, val, w, bagnum, weight);
      cout << endl;
      // auto end = std::chrono::steady_clock::now();
      //   std::chrono::duration<double, std::milli> elapsed =
      //       end - start;  // std::micro 表示以微秒为时间单位
      //   std::cout << "time: " << elapsed.count() << "ms" << std::endl;
      break;
    }
    case 3: {
      int bagnum, weight;
      fin.open("/Users/edith_lzh/Desktop/c++/algorithm/lab2/data2.dat");

      int l = 0;
      int data[4];
      int arr[4];
      // int all[6];
      for (l = 0; l < 8; l++) {
        if (l % 2 == 0) fin >> arr[l / 2];   // 1001 array, 1st is 0
        if (l % 2 == 1) fin >> data[l / 2];  // 1001 array, 1st is limit
      }
      fin.close();

      bagnum = arr[3];   // number of bags
      weight = data[0];  // limit

      int **val = new int *[bagnum + 1];  //这样定义二维数组，是为了方便传入
      val[0] = new int[(bagnum + 1) * (weight + 1)];
      for (i = 1; i <= bagnum; i++) val[i] = val[i - 1] + weight + 1;

      int *w = new int[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) w[i] = data[i];

      int *v = new int[bagnum + 1]();
      for (i = 1; i <= bagnum; i++) v[i] = w[i];

      cout << "max sum is" << maxVal(val, v, w, bagnum, weight) << '\n';

      int *exist = new int[bagnum]();  //为了查看我们选择了哪些包
      cout << "we get the bag num is:";
      insight(exist, val, w, bagnum, weight);
      cout << endl;
      break;
    }
  }
}
