# string类的模拟实现

该部分我只实现部分常用的部分函数

## string类的基本成员



| 基本成员                  | 作用                                             |
| ------------------------- | ------------------------------------------------ |
| char *_str                | 指向字符地址                                     |
| int   _size               | 字符串有效长度                                   |
| int  _capacity            | 字符总容量                                       |
| static const size_t  npos | 表示无限长，值为-1，当无符号整形为-1时，无无限大 |



# 常见构造

| (constructor)函数名称           | 功能说明                         |
| ------------------------------- | -------------------------------- |
| string() （重点）               | 构造空的string类对象，即空字符串 |
| string(const char* s) （重点）  | 用C-string来构造string类对象     |
| string(size_t n, char c)        | string类对象中包含n个字符c       |
| string(const string&s) （重点） | 拷贝构造函数                     |

```

```

