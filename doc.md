## 1.编码规范

### 1.1 头文件
- 在头文件中因使用`define _PROJECTNAME_FILENAME_H_`以防止头文件重复包含，示例如下所示:
```c
#ifndef _PROJECTNAME_FILENAME_H_
#define _PROJECTNAME_FILENAME_H_
...
#endif
```
- 函数若是无返回值操作，尽量减少`void`的使用，使用`int`作为返回值，`0`代表正常，`1`代表内部执行错误，`-1`代表操作不合法，或内存