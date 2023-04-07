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
int countPairs3(int *arr, int len, int value) {
  int q;
  int a;
  int n = 0;
  for (int i = 0; i < len; i++) {
    int left = i;
    int right = len;
    while (left < right-1) {
      q = (left + right) / 2;
      if (arr[i] + arr[q] == value) {
        n++;
        a = q + 1;
        while (arr[q] == arr[q + a] && (q + a) < right) {
          n++;
          a++;
        }
	  a = q - 1;
        while (arr[q] == arr[q - a] && (q - a) > left) {
          n++;
          a--;
        }
        break;
      }
      if (arr[i] + arr[q] > value) {
        right = q;
      } else {
        left = q;
      }
    }
  }
  return n;
}
