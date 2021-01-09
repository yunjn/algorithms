#ifndef MY_STRING
#define MY_STRING

typedef struct {
  char *str{nullptr};
  int length{0};
} String;

void StrAssign(String *S, const char *chars) {
  if (S->str) delete[] S->str;
  S->length = 0;
  while (chars[S->length] != '\0') S->length++;
  S->str = new char[S->length];
  int i = 0;
  while (chars[i] != '\0') {
    S->str[i] = chars[i];
    i++;
  }
}

int StrLength(String *S) { return S->length; }

int StrCompare(String str1, String str2) {
  for (int i = 0; i < str1.length && i < str2.length; i++)
    if (str1.str[i] != str2.str[i]) return (str1.str[i] - str2.str[i]);
  return str1.length - str2.length;
}

bool DestoryString(String *S) {
  if (!S->str) return false;
  delete[] S->str;
  S->str = nullptr;
  S->length = 0;
  return true;
}

String Concat(const String str1, const String str2) {
  String ret;
  ret.length = str1.length + str2.length;
  ret.str = new char[ret.length];
  for (int i = 0; i < str1.length; i++) ret.str[i] = str1.str[i];
  for (int i = 0; i < str2.length; i++) ret.str[str1.length + i] = str2.str[i];
  return ret;
}

String SubString(const String S, const int pos, const int len) {
  String sub;
  sub.str = new char[len];
  for (int i = 0; i < len; i++) sub.str[i] = S.str[pos - 1 + i];
  sub.length = len;
  return sub;
}

void Print(const String S) {
  int i = 0;
  while (S.str[i] != '\0') {
    std::cout << S.str[i];
    i++;
  }
  std::cout << std::endl;
}

void StrCopy(String *new_str, String *src) {
  int i = 0;
  while (i < src->length) {
    new_str->str[i] = src->str[i];
    i++;
  }
  new_str->length = src->length;
}

#endif