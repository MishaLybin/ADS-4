// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        a++;
      }
    }
  }
  return a;
}
int countPairs2(int *arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        a++;
      }
    }
  }
  return a;
}
int countPairs3(int* arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len - 1; i++) {
    int q = i, z = len;
    while (1 < z - q) {
      int qaz = (q + z) / 2;
      if (arr[i] + arr[qaz] == value) {
        a++;
        int k = qaz + 1;
        while (arr[i] + arr[k] == value && k < z) {
          a++;
          k++;
        }
        k = qaz - 1;
        while (arr[i] + arr[k] == value && k > q) {
          a++;
          k--;
        }
        break;
      }
      if (arr[i] + arr[qaz] > value) {
        z = qaz;
      } else {
        q = qaz;
      }
    }
  }
  return a;
}
