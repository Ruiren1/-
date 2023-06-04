# Linux权限

## Linux下的权限

Linux下有两种权限：超级用户(root)，普通用户

> 超级用户：可以再linux系统下做任何事情，不受限制
> 普通用户：在linux下做有限的事情。
> 超级用户的命令提示符是“#”，普通用户的命令提示符是“$”  

![image-20230513191539349](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513191539349.png)

> 命令： su [用户名]
> 功能：切换用户。
> 例如，要从root用户切换到普通用户user，则使用 su user。 要从普通用户user切换到root用户则使用 su
> root（root可以省略），此时系统会提示输入root用户的口令  

## Linux权限管理  

### 文件访问者的分类（人）

> 文件和文件目录的所有者： u---User（中国平民 法律问题）
> 文件和文件目录的所有者所在的组的用户： g---Group（不多说）
> 其它用户： o---Others （外国人）    



### 文件类型和访问权限（事物属性）  

![image-20230513193339893](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513193339893.png)





![image-20230513193351570](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513193351570.png)

![image-20230513193427207](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513193427207.png)



### 文件类型  

> d：文件夹
> -：普通文件
> l：软链接（类似Windows的快捷方式）
> b：块设备文件（例如硬盘、光驱等）
> p：管道文件
> c：字符设备文件（例如屏幕等串口设备）
> s：套接口文件  
>
> 

### 基本权限  

> i.读（r/4）： Read对文件而言，具有读取文件内容的权限；对目录来说，具有浏览该目录信息的权限
> ii.写（w/2）： Write对文件而言，具有修改文件内容的权限；对目录来说具有删除移动目录内文件的权限
> iii.执行（x/1）： execute对文件而言，具有执行文件的权限；对目录来说，具有进入目录的权限
> iv.“—”表示不具有该项权限  



### 文件权限值的表示方法  

#### 字符表示方法  

![image-20230513205500154](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513205500154.png)



#### 8进制数值表示方法  

![image-20230513205516848](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513205516848.png)

### 文件访问权限的相关设置方法  



#### chmod  

>  功能： 设置文件的访问权限
> 格式： chmod [参数] 权限 文件名
> 常用选项：  
>
> R -> 递归修改目录文件的权限
> 说明：==只有文件的拥有者和root才可以改变文件的权限==



##### 用户表示符+/-/=权限字符



> +:向权限范围增加权限代号所表示的权限
> -:向权限范围取消权限代号所表示的权限
> =:向权限范围赋予权限代号所表示的权限
> 用户符号：
> u：拥有者
> g：拥有者同组用
> o：其它用户
> a：所有用户  

![image-20230513210536044](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513210536044.png)

##### 三位8进制数字  

每一位八进制依次对应于每一位人

![image-20230513211026596](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513211026596.png)



![image-20230513211016668](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513211016668.png)

#### chown  

>  功能：修改文件的拥有者
> 格式： chown [参数] 用户名 文件名
>
> 实例：  
>
> \# chown user1 f1
> \# chown -R user1 filegroup1





#### chgrp  

> chgrp
>  功能：修改文件或目录的所属组
> 格式： chgrp [参数] 用户组名 文件名
> 常用选项： -R 递归修改文件或目录的所属组
> 实例：  chgrp users /abc/f2  



#### umask  

> 查看或修改文件掩码
> 新建文件夹默认权限=0666
> 新建目录默认权限=0777
> 但实际上你所创建的文件和目录，看到的权限往往不是上面这个值。原因就是创建文件或目录的时候还要受到
> umask的影响。假设默认权限是mask，则实际创建的出来的文件权限是: mask & ~umask  
>
> 格式： umask 权限值
> 说明：将现有的存取权限减去权限掩码后，即可产生建立文件时预设权限。超级用户默认掩码值为0022，普通用
> 户默认为0002  
>
> 实例：
>
> \# umask 755
> \# umask //查看
> \# umask 044//设置  

![image-20230513213545586](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230513213545586.png)

### 目录的权限  



> 可执行权限: 如果目录没有可执行权限, 则无法cd到目录中.  
>
> 可读权限: 如果目录没有可读权限, 则无法用ls等命令查看目录中的文件内容.
>
> 可写权限: 如果目录没有可写权限, 则无法在目录中创建文件, 也无法在目录中删除文件.  

==换句话来讲, 就是只要用户具有目录的写权限, 用户就可以删除目录中的文件, 而不论这个用户是否有这个文件的写
权限==

为了解决这个不科学的问题, Linux引入了粘滞位的概念  



当一个目录被设置为"粘滞位"(用chmod +t),则该目录下的文件只能由  

> 一、超级管理员删除
> 二、该目录的所有者删除
> 三、该文件的所有者删除  























