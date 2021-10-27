// #include <chrono>
// #include <fstream>
// #include <iostream>
// using namespace std;

// void Sort(int a[],int l, int r) {
//   for (int i = l; i <= r; i++) {
//     for (int j = i + 1; j <= r; j++) {
//       if (a[i] > a[j]) {
//         swap(a[i], a[j]);
//       }
//     }
//   }
// }
// int partition(int a[],int l, int r) {
//   int flag = a[l];
//   while (l < r) {
//     while (l < r && a[r] >= flag) r--;
//     if (l < r) {
//       swap(a[r], a[l]);
//     }
//     while (l < r && a[l] <= flag) l++;
//     if (l < r) {
//       swap(a[r], a[l]);
//     }
//   }
//   a[l] = flag;
//   return l;
// }
// int Select(int a[],int l, int r, int k) {
//   if (r - l + 1 < 75) {  //小于75个直接冒泡排序即可
//     Sort(a,l, r);
//     return a[l + k - 1];
//   }
//   for (int i = 0; i <= (r - l - 4) / 5; i++) {  // 55分组求中位数
//     int temp = Select(a,l + 5 * i, l + 5 * i + 4, 3);
//     swap(a[temp], a[l + i]);
//   }
//   int s = Select(a,l, l + (r - l - 4) / 5,
//                  l + (r - l - 4) / 10);  //找出中位数的中位数
//   swap(a[s], a[l]);                      //交换至首位作为快排标准
//   int p = partition(a,l, r);
//   int t = p - l + 1;  //前半部分的元素个数
//   if (k <= t) {
//     return Select(a,l, p, k);
//   } else {
//     return Select(a,p + 1, r, k - t);
//   }
// }
// void result(int n) {
//   switch (n) {
//     case 1: {
//       ifstream fin;
//       fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/10.txt");

//       int i = 0;
//       int data[10];
//       for (i = 0; i < 10; ++i) {
//         fin >> data[i];
//       }
//       cout << Select( data,1, 10, 6);
//       fin.close();
//       break;
//     }
//     case 2: {
//       ifstream fin;
//       fin.open("/Users/edith_lzh/Desktop/大三上/Algorithm/lab1/100.txt");

//       int i = 0;
//       int data[100];
//       for (i = 0; i < 100; ++i) {
//         fin >> data[i];
//       }
//       cout << Select(data, 1, 100, 50);
//       fin.close();
//       break;
//     }
//   }
// }

// int main() {
//   int n = 0;
//   cin >> n;
//   auto start = std::chrono::steady_clock::now();
//   result(n);
//   auto end = std::chrono::steady_clock::now();
//   std::chrono::duration<double, std::micro> elapsed =
//       end - start;  // std::micro 表示以微秒为时间单位
//   std::cout << "time: " << elapsed.count() << "us" << std::endl;
// }



#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;
#define M 1000000
int a[M]={3,1,7,6,5,9,8,2,0,4,13,11,17,16,15,19,18,12,10,14,23,21,27,26,25,29,28,22,20,24,33,31,37,36,35,39,38,32,30,34,43,41,47,46,45,49,48,42,40,44,53,51,57,56,55,59,58,52,50,54,63,61,67,66,65,69,68,62,60,64,73,71,77,76,75,79,78,72,70,74}, n=80;
void Sort(int l, int r){
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            if(a[i]>a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
int partition(int l, int r){
    int flag=a[l];
    while(l<r){
        while(l<r&&a[r]>=flag)
            r--;
        if(l<r){
            swap(a[r], a[l]);
        }
        while(l<r&&a[l]<=flag)
            l++;
        if(l<r){
            swap(a[r], a[l]);
        }
    }
    a[l]=flag;
    return l;
}
int Select(int l, int r, int k){
    if(r-l+1<75){//小于75个直接冒泡排序即可
        Sort(l, r);
        return l+k-1;
    }
    for(int i=0;i<=(r-l-4)/5;i++){//55分组求中位数
        int temp=Select(l+5*i, l+5*i+4, 3);
        swap(a[temp], a[l+i]);
    }
    int s=Select(l, l+(r-l-4)/5, l+(r-l-4)/10);//找出中位数的中位数
    swap(a[s], a[l]);//交换至首位作为快排标准
    int p=partition(l, r);
    int t=p-l+1;//前半部分的元素个数
    if(k<=t){
        return Select(l, p, k);
    }else{
        return Select(p+1, r, k-t);
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
      cout << Select(data, 0, 9, 1) << endl;
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
      cout << Select(data, 0, 99, 1) << endl;
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
      cout << Select(data, 0, 999, 503) << endl;
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
      cout << Select(data, 0, 999999, 500000) << endl;
      break;
    }
  }
}
int main()
{
    cout<<Select(0, n-1, 60)<<endl;
    getchar();
    return 0;
}

