[toc]
# redis

> Redis是一个开源的使用ANSI C语言编写、遵守BSD协议、支持网络、可基于内存亦可持久化的日志型、Key-Value数据库，并提供多种语言的API。

# 0.简介

## 0.1 特点



持久化
各种数据结构
数据备份

## 0.2 优势


性能
数据结构
原子
特性

## 0.3 配置


redis.conf

CONFIG GET CONFIG_SETTING_NAME

CONFIG GET *
CONFIG SET CONFIG_SETTING_NAME NEW_CONFIG_VALUE

## 0.4 数据类型


字符串string
哈希hash
列表list
集合set
有序集合 zset

|       类型	        |                                      简介	                                      |                                                            特性	                                                             |                                             场景                                             |
| ------------------- | --------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| String(字符串)	      | 二进制安全                                                                         | 	可以包含任何数据,比如jpg图片或者序列化的对象,一个键最大能存储512M                                                                | 	---                                                                                       |
| Hash(字典)           | 	键值对集合,即编程语言中的Map类型	                                                 | 适合存储对象,并且可以像数据库中update一个属性一样只修改某一项属性值(Memcached中需要取出整个字符串反序列化成对象修改完再序列化存回去)	 | 存储、读取、修改用户属性                                                                       |
| List(列表)	          | 链表(双向链表)                                                                      | 	增删快,提供了操作某一段元素的API	                                                                                              | 1,最新消息排行等功能(比如朋友圈的时间线) 2,消息队列                                              |
| Set(集合)	          | 哈希表实现,元素不重复                                                                | 	1、添加、删除,查找的复杂度都是O(1) 2、为集合提供了求交集、并集、差集等操作	                                                     | 1、共同好友 2、利用唯一性,统计访问网站的所有独立ip 3、好友推荐时,根据tag求交集,大于某个阈值就可以推荐 |
| Sorted Set(有序集合) | 	将Set中的元素增加一个权重参数score,元素按score有序排列	数据插入集合时,已经进行天然排序	 | 1、排行榜 2、带权重的消息队列                                                                                                  |                                                                                             |

### 0.4.1 字符串string
string 类型是二进制安全的。意思是 redis 的 string 可以包含任何数据。比如jpg图片或者序列化的对象。
string 类型是 Redis 最基本的数据类型

### 0.4.2 哈希hash
是一个 string 类型的 field 和 value 的映射表，hash 特别适合用于存储对象。
```redis
HMSET runoob field1 "Hello" field2 "World"
HGET runoob field2
```
每个 hash 可以存储 2^32 -1 键值对（40多亿）

### 0.4.3 列表list
添加一个元素到列表的头部（左边）或者尾部（右边）。
```redis
redis 127.0.0.1:6379> DEL runoob
redis 127.0.0.1:6379> lpush runoob redis
(integer) 1
redis 127.0.0.1:6379> lpush runoob mongodb
(integer) 2
redis 127.0.0.1:6379> lpush runoob rabitmq
(integer) 3
redis 127.0.0.1:6379> lrange runoob 0 10
1) "rabitmq"
2) "mongodb"
3) "redis"
```
### 0.4.4 集合set
Redis 的 Set 是 string 类型的无序集合。
集合是通过哈希表实现的，所以添加，删除，查找的复杂度都是 O(1)。

sadd添加一个 string 元素到 key 对应的 set 集合中，成功返回 1，如果元素已经在集合中返回 0。

```redis
redis 127.0.0.1:6379> DEL runoob
redis 127.0.0.1:6379> sadd runoob redis
(integer) 1
redis 127.0.0.1:6379> sadd runoob mongodb
(integer) 1
redis 127.0.0.1:6379> sadd runoob rabitmq
(integer) 1
redis 127.0.0.1:6379> sadd runoob rabitmq
(integer) 0
redis 127.0.0.1:6379> smembers runoob
1) "redis"
2) "rabitmq"
3) "mongodb"
```
### 0.4.5 有序集合 zset
Redis zset 和 set 一样也是string类型元素的集合,且不允许重复的成员。
不同的是每个元素都会关联一个double类型的分数。redis正是通过分数来为集合中的成员进行从小到大的排序。
zset的成员是唯一的,但分数(score)却可以重复。
```redis
redis 127.0.0.1:6379> DEL runoob
redis 127.0.0.1:6379> zadd runoob 0 redis
(integer) 1
redis 127.0.0.1:6379> zadd runoob 0 mongodb
(integer) 1
redis 127.0.0.1:6379> zadd runoob 0 rabitmq
(integer) 1
redis 127.0.0.1:6379> zadd runoob 0 rabitmq
(integer) 0
redis 127.0.0.1:6379> > ZRANGEBYSCORE runoob 0 1000
1) "mongodb"
2) "rabitmq"
3) "redis"
```

# 1. 命令
```redis
redis-cli -h host -p port -a password
> PING
PONG
```
`redis-cli --raw` 就可以避免中文乱码了。
## 1.1 Redis 键(key)


```redis
DEL key
DUMP key
EXIST key
EXPIRE key 过期时间，以秒计
EXPIREAT key 接受的参数为 timestamp UNIX时间戳
PEXPIRE key milliseconds 毫秒
PEXPIREAT key milliseconds-timestamp  时间戳(unix timestamp) 以毫秒计
KEYS pattern
MOVE key db
PERSIST key 移除过期时间
PTTL key 毫秒返回key剩余过期时间
TTL key 剩余生存时间(TTL, time to live)。
RANDOMKEY 随机返回
RENAME key newkey 改名
RENAMENX key newkey 仅当 newkey 不存在时，将 key 改名为 newkey
SCAN cursor [MATCH pattern] [COUNT count] 迭代数据库中的数据库键
```
> SCAN 命令是一个基于游标的迭代器，每次被调用之后， 都会向用户返回一个新的游标， 用户在下次迭代时需要使用这个新游标作为 SCAN 命令的游标参数， 以此来延续之前的迭代过程。
> SCAN 返回一个包含两个元素的数组， 第一个元素是用于进行下一次迭代的新游标， 而第二个元素则是一个数组， 这个数组中包含了所有被迭代的元素。如果新游标返回 0 表示迭代已结束。
```
TYPE key
```
## 1.2 Redis 字符串(String)


### 1.2.1 `SET key value`
### 1.2.2 `GET key`
### 1.2.3 `GETRANGE key start end`
> 返回 key 中字符串值的子字符
```redis
> redis 127.0.0.1:6379> SET mykey "This is my test key"
> OK
>redis 127.0.0.1:6379> GETRANGE mykey 0 3
>"This"
>redis 127.0.0.1:6379> GETRANGE mykey 0 -1
>"This is my test key"
```
### 1.2.4 `GETSET key value`
> 将给定 key 的值设为 value ，并返回 key 的旧值(old value)。
```redis
> redis> GETSET db mongodb    # 没有旧值，返回 nil
> (nil)
> redis> GET db
> "mongodb"
> redis> GETSET db redis      # 返回旧值 mongodb
> "mongodb"
> redis> GET db
>"redis"
```

### 1.2.5 `SETBIT key offset value`
> 对 key 所储存的字符串值，设置或清除指定偏移量上的位(bit)。

### 1.2.6 `GETBIT KEY_NAME OFFSET `
```redis
> Redis Getbit 命令用于对 key 所储存的字符串值，获取指定偏移量上的位(bit)。
>  对不存在的 key 或者不存在的 offset 进行 GETBIT， 返回 0
> redis> EXISTS bit
> (integer) 0
> redis> GETBIT bit 10086
> (integer) 0
>  对已存在的 offset 进行 GETBIT
> redis> SETBIT bit 10086 1
> (integer) 0
> redis> GETBIT bit 10086
> (integer) 1
```

### 1.2.7 `MGET key1 [key2..]`
```redis
> 一个包含所有给定 key 的值的列表。
> redis 127.0.0.1:6379> SET key1 "hello"
> OK
> redis 127.0.0.1:6379> SET key2 "world"
> OK
> redis 127.0.0.1:6379> MGET key1 key2 someOtherKey
> 1) "Hello"
> 2) "World"
> 3) (nil)
```

### 1.2.8 `SETEX key seconds value`
```redis
> 设置成功时返回 OK 。
> 127.0.0.1:6379> SETEX mykey 60 redis
> OK
> 127.0.0.1:6379> TTL mykey
> (integer) 55
> 127.0.0.1:6379> TTL mykey
> (integer) 50
> 127.0.0.1:6379> get mykey
> "redis"
> 127.0.0.1:6379> SETEX mykey 60 redis2
>OK
> 127.0.0.1:6379> TTL mykey
> (integer) 56
> 127.0.0.1:6379> get mykey
> "redis2"
> 127.0.0.1:6379> TTL mykey
> (integer) 25
> 127.0.0.1:6379> get mykey
> (nil)
> 127.0.0.1:6379> TTL mykey
> (integer) -2
```

### 1.2.9 `PSETEX key1 EXPIRY_IN_MILLISECONDS value1 `
以毫秒为单位设置 key 的生存时间
```redis
127.0.0.1:6379> PSETEX mykey 2000 "Hello"
OK
127.0.0.1:6379> PTTL mykey
(integer) 569
127.0.0.1:6379> PTTL mykey
(integer) -2
127.0.0.1:6379> GET mykey
(nil)
```
### 1.2.10 `SETNX key value`
> 只有在 key 不存在时设置 key 的值。
Setnx（SET if Not eXists） 命令在指定的 key 不存在时，为 key 设置指定的值。
```redis
> redis> EXISTS job                # job 不存在
> (integer) 0
> redis> SETNX job "programmer"    # job 设置成功
> (integer) 1
> redis> SETNX job "code-farmer"   # 尝试覆盖 job ，失败
> (integer) 0
> redis> GET job                   # 没有被覆盖
> "programmer"
```

### 1.2.11 `SETRANGE key offset value`
用 value 参数覆写给定 key 所储存的字符串值，从偏移量 offset 开始。
```redis
> 127.0.0.1:6379> SET key1 "Hello World"
> OK
> 127.0.0.1:6379> SETRANGE key1 6 "Redis"
> (integer) 11
> 127.0.0.1:6379> GET key1
> "Hello Redis"
> 127.0.0.1:6379> SETRANGE key1 6 "r"
> (integer) 11
> 127.0.0.1:6379> GET key1
> "Hello redis"
```

### 1.2.12 `STRLEN key`
返回 key 所储存的字符串值的长度, 当 key 不存在时，返回 0

### 1.2.13 `MSET key1 value1 key2 value2 .. keyN valueN`
> 同时设置一个或多个 key-value 对
```redis
> redis 127.0.0.1:6379> MSET key1 "Hello" key2 "World"
> OK
> redis 127.0.0.1:6379> GET key1
> "Hello"
> redis 127.0.0.1:6379> GET key2
> "World"
```

### 1.2.14 `MSETNX key1 value1 key2 value2 .. keyN valueN`
```redis
# 对不存在的 key 进行 MSETNX
redis> MSETNX rmdbs "MySQL" nosql "MongoDB" key-value-store "redis"
(integer) 1
redis> MGET rmdbs nosql key-value-store
1) "MySQL"
2) "MongoDB"
3) "redis"
# MSET 的给定 key 当中有已存在的 key
redis> MSETNX rmdbs "Sqlite" language "python"  # rmdbs 键已经存在，操作失败
(integer) 0
redis> EXISTS language                          # 因为 MSET 是原子性操作，language 没有被设置
(integer) 0
redis> GET rmdbs                                # rmdbs 也没有被修改
"MySQL"
```
### 1.2.15 `INCR key`
> 增加1，不存在为0+1，错误类型返回错误，64位有符号数字
```redis
127.0.0.1:6379> incr key2
(error) ERR value is not an integer or out of range
127.0.0.1:6379> incr key3
(integer) 1
```

### 1.2.16 `INCRBY KEY_NAME INCR_AMOUNT`
```redis
# key 存在且是数字值
redis> SET rank 50
OK
redis> INCRBY rank 20
(integer) 70
redis> GET rank
"70"

# key 不存在时
redis> EXISTS counter
(integer) 0
redis> INCRBY counter 30
(integer) 30
redis> GET counter
"30"

# key 不是数字值时
redis> SET book "long long ago..."
OK
redis> INCRBY book 200
(error) ERR value is not an integer or out of range
```
### 1.2.17 `INCRBYFLOAT KEY_NAME INCR_AMOUNT`
> 为 key 中所储存的值加上指定的浮点数增量值
> 不存在设为0

```redis
# 值和增量都不是指数符号
redis> SET mykey 10.50
OK
redis> INCRBYFLOAT mykey 0.1
"10.6"

# 值和增量都是指数符号
redis> SET mykey 314e-2
OK
redis> GET mykey                # 用 SET 设置的值可以是指数符号
"314e-2"
redis> INCRBYFLOAT mykey 0      # 但执行 INCRBYFLOAT 之后格式会被改成非指数符号
"3.14"

# 可以对整数类型执行
redis> SET mykey 3
OK
redis> INCRBYFLOAT mykey 1.1
"4.1"
# 后跟的 0 会被移除
redis> SET mykey 3.0
OK
redis> GET mykey                                    # SET 设置的值小数部分可以是 0
"3.0"
redis> INCRBYFLOAT mykey 1.000000000000000000000    # 但 INCRBYFLOAT 会将无用的 0 忽略掉，有需要的话，将浮点变为整数
"4"
redis> GET mykey
"4"
```

### 1.2.18 `DECR key`
> 将 key 中储存的数字值减一
> 如果 key 不存在，那么 key 的值会先被初始化为 0 ，然后再执行 DECR 操作

### 1.2.19 `DECRBY key decrement`
> key 所储存的值减去给定的减量值（decrement） 。

### 1.2.20 `APPEND key value`
> 为指定的 key 追加值,
> key不存在， APPEND 就简单地将给定 key 设为 value

```redis
# 对不存在的 key 执行 APPEND
redis> EXISTS myphone               # 确保 myphone 不存在
(integer) 0
redis> APPEND myphone "nokia"       # 对不存在的 key 进行 APPEND ，等同于 SET myphone "nokia"
(integer) 5                         # 字符长度
# 对已存在的字符串进行 APPEND
redis> APPEND myphone " - 1110"     # 长度从 5 个字符增加到 12 个字符
(integer) 12
redis> GET myphone
"nokia - 1110
```
## 1.3 Redis 哈希(Hash)


> 是一个 string 类型的 field（字段） 和 value（值） 的映射表
### 1.3.1 HDEL key field1 [field2]
> 删除哈希表 key 中的一个或多个指定字段，不存在的字段将被忽略。
### 1.3.2. HEXISTS key field
> 查看哈希表 key 中，指定的字段是否存在。
### 1.3.3. HGET key field
> 获取存储在哈希表中指定字段的值。
### 1.3.4. HGETALL key
> 获取在哈希表中指定 key 的所有字段和值
### 1.3.5. HINCRBY key field increment
> 为哈希表 key 中的指定字段的整数值加上增量 increment 。
### 1.3.6. HINCRBYFLOAT key field increment
>为哈希表 key 中的指定字段的浮点数值加上增量 increment 。
### 1.3.7. HKEYS key
> 获取所有哈希表中的字段
```redis
127.0.0.1:6379> hkeys Md:Ag99.9:
1) "lastprice"
2) "volume"
```
### 1.3.8. HLEN key
> 获取哈希表中字段的数量
### 1.3.9. HMGET key field1 [field2]
> 获取所有给定字段的值
### 1.3.10. HMSET key field1 value1 [field2 value2 ]
> 同时将多个 field-value (域-值)对设置到哈希表 key 中。
### 1.3.11. HSET key field value
> 将哈希表 key 中的字段 field 的值设为 value 。
### 1.3.12. HSETNX key field value
> 只有在字段 field 不存在时，设置哈希表字段的值。
### 1.3.13. HVALS key
> 获取哈希表中所有值。
### 1.3.14. HSCAN key cursor [MATCH pattern] [COUNT count]
> 迭代哈希表中的键值对。

## 1.4 Redis 列表(List)


> 列表是简单的字符串列表，按照插入顺序排序。你可以添加一个元素到列表的头部（左边）或者尾部（右边）
### 1.4.1 BLPOP key1 [key2 ] timeout
移出并获取列表的第一个元素， 如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止。

```redis
127.0.0.1:6379> keys list1
(empty list or set)
127.0.0.1:6379> BLPOP list1 10
(nil)
(10.04s)

127.0.0.1:6379> LPUSH list1 redis
(integer) 1

127.0.0.1:6379> BLPOP list1 20
1) "list1"
2) "redis"
(11.31s)
```
### 1.4.2 BRPOP key1 [key2 ] timeout
> 移出并获取列表的最后一个元素， 如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止。
> 假如在指定时间内没有任何元素被弹出，则返回一个 nil 和等待时长
> 返回一个含有两个元素的列表，第一个元素是被弹出元素所属的 key ，第二个元素是被弹出元素的值。
```redis
127.0.0.1:6379> RPUSH list2 a b c
(integer) 3
127.0.0.1:6379> BRPOP list1 list2 0
1) "list1"
2) "redis"
127.0.0.1:6379> BRPOP list1 list2 10
1) "list1"
2) "nosql"
```
### 1.4.3 BRPOPLPUSH source destination timeout
> 从列表中弹出一个值，将弹出的元素插入到另外一个列表中并返回它； 如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止。
> BRPOPLPUSH LIST1 ANOTHER_LIST TIMEOUT
```redis
127.0.0.1:6379> BRPOPLPUSH list2 list3 5
"c"
127.0.0.1:6379> LLEN list3
(integer) 1
127.0.0.1:6379> LLEN list3
(integer) 1
127.0.0.1:6379> LRANGE list3 0 0
1) "c"
```
### 1.4.4 LINDEX key index
通过索引获取列表中的元素
```redis
127.0.0.1:6379> LRANGE list2 0 3
1) "a"
2) "b"
127.0.0.1:6379> LINDEX list2 0
"a"
127.0.0.1:6379> LINDEX list2 -1
"b"
127.0.0.1:6379> LINDEX list2 3
(nil)
```
### 1.4.5 LINSERT key BEFORE|AFTER pivot value
> 在列表的元素前或者后插入元素
> 用于在列表的元素前或者后插入元素。当指定元素不存在于列表中时，不执行任何操作。
> 当列表不存在时，被视为空列表，不执行任何操作。
> 如果 key 不是列表类型，返回一个错误。
`LINSERT key BEFORE|AFTER pivot value`
```redis
127.0.0.1:6379> RPUSH mylist "HEllo" "World"
(integer) 2
127.0.0.1:6379> LINSERT mylist BEFORE "World" "There"
(integer) 3
127.0.0.1:6379> LRANGE mylist 0 -1
1) "HEllo"
2) "There"
3) "World"
127.0.0.1:6379> LINSERT mylist AFTER "World" "EMMM"
(integer) 4
127.0.0.1:6379> LRANGE mylist 0 -1
1) "HEllo"
2) "There"
3) "World"
4) "EMMM"
```
### 1.4.6 LLEN key
获取列表长度
```redis
127.0.0.1:6379> LLEN list1
(integer) 1
127.0.0.1:6379> RPUSH list1 "foo"
(integer) 2
127.0.0.1:6379> RPUSH list1 "bar"
(integer) 3
127.0.0.1:6379> LLEN list1
(integer) 3
```
### 1.4.7 LPOP key
> 移除并获取列表的第一个元素
> 列表的第一个元素。 当列表 key 不存在时，返回 nil 。
```redis
127.0.0.1:6379> LPOP key123
(nil)
127.0.0.1:6379> LPOP list1
"mongodb"
```

### 1.4.8 LPUSH key value1 [value2]
将一个或多个值插入到列表头部
### 1.4.9 LPUSHX key value
> 将一个值插入到已存在的列表头部
> Lpushx 将一个值插入到已存在的列表头部，列表不存在时操作无效。
```redis
127.0.0.1:6379> LPUSH list1 "foo"
(integer) 1
127.0.0.1:6379> LPUSHX list1 "bar"
(integer) 2
```
### 1.4.10 LRANGE key start stop
获取列表指定范围内的元素
返回列表中指定区间内的元素，区间以偏移量 START 和 END 指定。
其中 0 表示列表的第一个元素， 1 表示列表的第二个元素，以此类推。
你也可以使用负数下标，以 -1 表示列表的最后一个元素， -2 表示列表的倒数第二个元素，以此类推。
```redis
redis 127.0.0.1:6379> LRANGE KEY_NAME START END
redis> LRANGE mylist -100 100
1) "one"
2) "two"
3) "three"
redis> LRANGE mylist 5 10
(empty list or set)
```
### 1.4.11 LREM key count value
移除列表元素
Lrem 根据参数 COUNT 的值，移除列表中与参数 VALUE 相等的元素。
COUNT 的值可以是以下几种：
- count > 0 : 从表头开始向表尾搜索，移除与 VALUE 相等的元素，数量为 COUNT 。
- count < 0 : 从表尾开始向表头搜索，移除与 VALUE 相等的元素，数量为 COUNT 的绝对值。
- count = 0 : 移除表中所有与 VALUE 相等的值。
`127.0.0.1:6379> LREM key count VALUE`

```redis
127.0.0.1:6379> LRANGE mylist 0 -1
1) "HEllo"
2) "There"
3) "World"
4) "EMMM"
5) "hello"
6) "hello"
7) "foo"
8) "hello"

127.0.0.1:7379> LREM mylist -2 "hello"
(integer)2

127.0.0.1:6379> LRANGE mylist 0 -1
1) "HEllo"
2) "There"
3) "World"
4) "EMMM"
5) "hello"
6) "foo"
```
### 1.4.12 LSET key index value
> 通过索引设置列表元素的值
`LSET KEY_NAME INDEX VALUE`

```redis
127.0.0.1:6379> LRANGE mylist 0 -1
1) "HEllo"
2) "There"
3) "World"
4) "EMMM"
5) "hello"
6) "foo"
127.0.0.1:6379> LSET mylist 0 "bar"
OK
127.0.0.1:6379> LRANGE mylist 0 -1
1) "bar"
2) "There"
3) "World"
4) "EMMM"
5) "hello"
6) "foo"
```
### 1.4.13 LTRIM key start stop
> 对一个列表进行修剪(trim)，就是说，让列表只保留指定区间内的元素，不在指定区间之内的元素都将被删除。
`LTRIM KEY_NAME START STOP`

```redis
127.0.0.1:6379> LTRIM mylist 1 -1
OK
127.0.0.1:6379> LRANGE mylist 0 -1
1) "There"
2) "World"
3) "EMMM"
4) "hello"
5) "foo"
```
### 1.4.14 RPOP key
> 移除列表的最后一个元素，返回值为移除的元素。
`RPOP KEY_NAME `

### 1.4.15 RPOPLPUSH source destination
> 移除列表的最后一个元素，并将该元素添加到另一个列表并返回

```redis
127.0.0.1:6379> LRANGE mylist 0 -1
1) "There"
2) "World"
3) "EMMM"
4) "hello"
5) "foo"
127.0.0.1:6379> RPOPLPUSH mylist myotherlist
"foo"
127.0.0.1:6379> LRANGE myotherlist 0 -1
1) "foo"
127.0.0.1:6379> LRANGE mylist 0 -1
1) "There"
2) "World"
3) "EMMM"
4) "hello"
```
### 1.4.16 RPUSH key value1 [value2]
> 在列表中添加一个或多个值
`RPUSH KEY_NAME VALUE1..VALUEN`

### 1.4.17 RPUSHX key value
> 为已存在的列表添加值,
> 插入到已存在的列表尾部(最右边)。如果列表不存在，操作无效
`RPUSHX KEY_NAME VALUE1..VALUEN`

## 1.5 Redis 集合(Set)


>  Set 是 String 类型的无序集合。集合成员是唯一的，这就意味着集合中不能出现重复的数据。
> Redis 中集合是通过哈希表实现的，所以添加，删除，查找的复杂度都是 O(1)。

### 1.5.1 SADD key member1 [member2]
> 向集合添加一个或多个成员
`SADD KEY_NAME VALUE1..VALUEN`
```redis
127.0.0.1:6379> keys myset
(empty list or set)
127.0.0.1:6379> sadd myset "hello" "foo"
(integer) 2
127.0.0.1:6379> sadd myset "hello"
(integer) 0
127.0.0.1:6379> SMEMBERS myset
1) "foo"
2) "hello"
```
### 1.5.2 SCARD key
> 获取集合的成员数
`SCARD KEY_NAME `
```redis
127.0.0.1:6379> SCARD myset
(integer) 2
```

### 1.5.3 SDIFF key1 [key2]
> 返回第一个集合与其他集合之间的差异。
`SDIFF FIRST_KEY OTHER_KEY1..OTHER_KEYN `
```redis
127.0.0.1:6379> SADD key1 a b c
(integer) 3
127.0.0.1:6379> SADD key2 c d e
(integer) 3
127.0.0.1:6379> sadd key3 a d r
(integer) 3
127.0.0.1:6379> SDIFF key1 key2
1) "a"
2) "b"
127.0.0.1:6379> SDIFF key1 key3
1) "c"
2) "b"
127.0.0.1:6379> SDIFF key2 key3
1) "c"
2) "e"
127.0.0.1:6379> SDIFF key1 key2 key3
1) "b"
```
### 1.5.4 SDIFFSTORE destination key1 [key2]
> 返回给定所有集合的差集并存储在 destination 中
> Sdiffstore 命令将给定集合之间的差集存储在指定的集合中。如果指定的集合 key 已存在，则会被覆盖。
```redis
127.0.0.1:6379> SMEMBERS myset
1) "bar"
2) "foo"
3) "hello"
127.0.0.1:6379> SMEMBERS myset2
1) "world"
2) "hello"
127.0.0.1:6379> SDIFFSTORE destset myset myset2
(integer) 2
127.0.0.1:6379> SMEMBERS destset
1) "foo"
2) "bar"
```
### 1.5.5 SINTER key1 [key2]
> 返回给定所有集合的交集
> 不存在的集合 key 被视为空集。 当给定集合当中有一个空集时，结果也为空集(根据集合运算定律)。
```redis
127.0.0.1:6379> SINTER myset myset2
1) "hello"
```
### 1.5.6 SINTERSTORE destination key1 [key2]
> 返回给定所有集合的交集并存储在 destination 中
`SINTERSTORE DESTINATION_KEY KEY KEY1..KEYN `
```redis
127.0.0.1:6379> SMEMBERS myset1
1) "bar"
2) "foo"
3) "hello"
127.0.0.1:6379> SMEMBERS myset2
1) "world"
2) "hello"
127.0.0.1:6379> SINTERSTORE myset myset1 myset2
(integer) 1
127.0.0.1:6379> SMEMBERS myset
1) "hello"
```
### 1.5.7 SISMEMBER key member
> 判断 member 元素是否是集合 key 的成员
`SISMEMBER KEY VALUE`
```redis
127.0.0.1:6379> SISMEMBER myset1 "hello"
(integer) 1
127.0.0.1:6379> SISMEMBER myset1 "world"
(integer) 0
```
### 1.5.8 SMEMBERS key
> 返回集合中的所有成员
`SMEMBERS key`
### 1.5.9 SMOVE source destination member
> 将 member 元素从 source 集合移动到 destination 集合
> Smove 命令将指定成员 member 元素从 source 集合移动到 destination 集合。
> SMOVE 是原子性操作。
> 如果 source 集合不存在或不包含指定的 member 元素，则 SMOVE 命令不执行任何操作，仅返回 0 。否则， member 元素从 source 集合中被移除，并添加到 destination 集合中去。
> 当 destination 集合已经包含 member 元素时， SMOVE 命令只是简单地将 source 集合中的 member 元素删除。
> 当 source 或 destination 不是集合类型时，返回一个错误。
```redis
127.0.0.1:6379> SMEMBERS myset1
1) "bar"
2) "foo"
3) "hello"
4) "world"
127.0.0.1:6379> SMEMBERS myset2
1) "world"
2) "hello"
127.0.0.1:6379> SMOVE myset1 myset2 "bar"
(integer) 1
127.0.0.1:6379> SMEMBERS myset1
1) "foo"
2) "world"
3) "hello"
127.0.0.1:6379> SMEMBERS myset2
1) "bar"
2) "world"
3) "hello"
127.0.0.1:6379>
```
### 1.5.10 SPOP key
> 移除并返回集合中的一个随机元素
> 用于移除集合中的指定 key 的一个或多个随机元素，移除后会返回移除的元素。
> 该命令类似 Srandmember 命令，但 SPOP 将随机元素从集合中移除并返回，而 Srandmember 则仅仅返回随机元素，而不对集合进行任何改动。
```redis
127.0.0.1:6379> SADD myset "one" "two" "three"
(integer) 3
127.0.0.1:6379> SPOP myset
"three"
127.0.0.1:6379> SMEMBERS myset
1) "two"
2) "one"
127.0.0.1:6379> SADD myset "four"
(integer) 1
127.0.0.1:6379> SADD myset "five"
(integer) 1
127.0.0.1:6379> SPOP myset 3
1) "two"
2) "one"
3) "five"
127.0.0.1:6379> SMEMBERS myset
1) "four"
```
### 1.5.11 SRANDMEMBER key [count]
> 返回集合中一个或多个随机数
> Srandmember 命令用于返回集合中的一个随机元素。
> 从 Redis 2.6 版本开始， Srandmember 命令接受可选的 count 参数：
> 如果 count 为正数，且小于集合基数，那么命令返回一个包含 count 个元素的数组，数组中的元素各不相同。如果 count 大于等于集合基数，那么返回整个集合。
> 如果 count 为负数，那么命令返回一个数组，数组中的元素可能会重复出现多次，而数组的长度为 count 的绝对值。
> 该操作和 SPOP 相似，但 SPOP 将随机元素从集合中移除并返回，而 Srandmember 则仅仅返回随机元素，而不对集合进行任何改动
```redis
127.0.0.1:6379> SRANDMEMBER myset1
"world"
127.0.0.1:6379> SRANDMEMBER myset1 2
1) "hello"
2) "world"
127.0.0.1:6379> SRANDMEMBER myset1
"foo"
127.0.0.1:6379> SRANDMEMBER myset1 2
1) "foo"
2) "hello"
127.0.0.1:6379> SRANDMEMBER myset1 -2
1) "world"
2) "world"
127.0.0.1:6379> SRANDMEMBER myset1 -2
1) "foo"
2) "hello"
127.0.0.1:6379> SRANDMEMBER myset1 4
1) "foo"
2) "hello"
3) "world"
127.0.0.1:6379> SRANDMEMBER myset1 -4
1) "hello"
2) "world"
3) "foo"
4) "foo"
```
### 1.5.12 SREM key member1 [member2]
> 移除集合中一个或多个成员
> Srem 命令用于移除集合中的一个或多个成员元素，不存在的成员元素会被忽略。
> 当 key 不是集合类型，返回一个错误。
```redis
127.0.0.1:6379> SMEMBERS myset1
1) "foo"
2) "world"
3) "hello"
127.0.0.1:6379> SREM myset1 "hello"
(integer) 1
127.0.0.1:6379> SREM myset1 "bar"
(integer) 0
127.0.0.1:6379> SMEMBERS myset1
1) "foo"
2) "world"
```
### 1.5.13 SUNION key1 [key2]
> 返回所有给定集合的并集
> 不存在的集合 key 被视为空集。
```redis
127.0.0.1:6379> SMEMBERS key1
1) "c"
2) "b"
3) "a"
127.0.0.1:6379> SMEMBERS key2
1) "d"
2) "e"
3) "c"
127.0.0.1:6379> SUNION key1 key2
1) "c"
2) "a"
3) "b"
4) "d"
5) "e"
```
### 1.5.14 SUNIONSTORE destination key1 [key2]
> 将给定集合的并集存储在指定的集合 destination 中。如果 destination 已经存在，则将其覆盖。
```redis
127.0.0.1:6379> SUNIONSTORE key key1 key2
(integer) 5
127.0.0.1:6379> SMEMBERS key
1) "c"
2) "a"
3) "b"
4) "d"
5) "e"
```
### 1.5.15 SSCAN key cursor [MATCH pattern] [COUNT count]
> 迭代集合中的元素
> Sscan 命令用于迭代集合中键的元素，Sscan 继承自 Scan。
`SSCAN key cursor [MATCH pattern] [COUNT count]`
- cursor - 游标。
- pattern - 匹配的模式。
- count - 指定从数据集里返回多少元素，默认值为 10 。

```redis
127.0.0.1:6379> SMEMBERS myset1
1) "hi"
2) "foo"
3) "hello"
4) "world"
5) "bar"
127.0.0.1:6379> sscan myset1 0 match h*
1) "0"
2) 1) "hi"
   2) "hello"
127.0.0.1:6379> sscan myset1 0 match *o*
1) "0"
2) 1) "foo"
   2) "hello"
   3) "world"
```
## 1.6 Redis 有序集合(sorted set)


> 在redis sorted sets里面当items内容大于64的时候同时使用了hash和skiplist两种设计实现。这也会为了排序和查找性能做的优化。所以如上可知：
> 添加和删除都需要修改skiplist，所以复杂度为O(log(n))。
> 但是如果仅仅是查找元素的话可以直接使用hash，其复杂度为O(1)
> 其他的range操作复杂度一般为O(log(n))
> 当然如果是小于64的时候，因为是采用了ziplist的设计，其时间复杂度为O(n)
### 1.6.1 ZADD key score1 member1 [score2 member2]
`ZADD KEY_NAME SCORE1 VALUE1.. SCOREN VALUEN`
> 向有序集合添加一个或多个成员，或者更新已存在成员的分数
> 如果某个成员已经是有序集的成员，那么更新这个成员的分数值，并通过重新插入这个成员元素，来保证该成员在正确的位置上。
> 分数值可以是整数值或双精度浮点数。
> 如果有序集合 key 不存在，则创建一个空的有序集并执行 ZADD 操作。
> 当 key 存在但不是有序集类型时，返回一个错误。
```redis
redis> ZADD myzset 1 "one"
(integer) 1
redis> ZADD myzset 1 "uno"
(integer) 1
redis> ZADD myzset 2 "two" 3 "three"
(integer) 2
redis> ZRANGE myzset 0 -1 WITHSCORES
1) "one"
2) "1"
3) "uno"
4) "1"
5) "two"
6) "2"
7) "three"
8) "3"
```
### 1.6.2 ZCARD key
> 获取有序集合的成员数

```redis
redis> ZCARD myzset
(integer) 4
```
### 1.6.3 ZCOUNT key min max
`ZCOUNT key min max`
> 计算在有序集合中指定区间分数的成员数
```redis
127.0.0.1:6379> ZCOUNT myzset 1 3
(integer) 4
127.0.0.1:6379> ZCOUNT myzset 0 1
(integer) 2
```
### 1.6.4 ZINCRBY key increment member
` ZINCRBY key increment member`
> 有序集合中对指定成员的分数加上增量 increment
```redis
127.0.0.1:6379> ZADD  myzset 1 "one" 2 "two"
(integer) 2
127.0.0.1:6379> ZINCRBY myzset 2 "one"
"3"
127.0.0.1:6379> ZRANGE myzset 0 -1 WITHSCORES
1) "two"
2) "2"
3) "one"
4) "3"
```
### 1.6.5 ZINTERSTORE destination numkeys key [key ...]
`ZINTERSTORE destination numkeys key [key ...] [WEIGHTS weight [weight ...]] [AGGREGATE SUM|MIN|MAX]`
> 计算给定的一个或多个有序集的交集并将结果集存储在新的有序集合 destination 中
```redis
127.0.0.1:6379> keys mid_test
(empty list or set)
127.0.0.1:6379> ZADD mid_test 70 "Li Lei"
(integer) 1
127.0.0.1:6379> ZADD mid_test 70 "Han Meimei"
(integer) 1
127.0.0.1:6379> ZADD mid_test 99.5 "Tom"
(integer) 1
127.0.0.1:6379> ZADD fin_test 88 "Li Lei" 75 "Han Meimei" 99.5 "Tom"
(integer) 3
127.0.0.1:6379> ZINTERSTORE sum_point 2 mid_test fin_test
(integer) 3
127.0.0.1:6379> ZRANGE sum_point 0 -1 WITHSCORES
1) "Han Meimei"
2) "145"
3) "Li Lei"
4) "158"
5) "Tom"
6) "199"
```
### 1.6.6 ZLEXCOUNT key min max
`ZLEXCOUNT KEY MIN MAX`
> 在有序集合中计算指定字典区间内成员数量
```redis
127.0.0.1:6379> ZADD myzset 0 a 0 b 0 c 0 d 0 e
(integer) 5
127.0.0.1:6379> ZADD myzset 0 f 0 g
(integer) 2
127.0.0.1:6379> ZRANGE myzset 0 -1 WITHSCORES
 1) "a"
 2) "0"
 3) "b"
 4) "0"
 5) "c"
 6) "0"
 7) "d"
 8) "0"
 9) "e"
10) "0"
11) "f"
12) "0"
13) "g"
14) "0"
15) "two"
16) "2"
17) "one"
18) "3"
127.0.0.1:6379> ZLEXCOUNT myzset - +
(integer) 9
127.0.0.1:6379> ZLEXCOUNT myzset [b [f
(integer) 5
```
### 1.6.7 ZRANGE key start stop [WITHSCORES]
> 通过索引区间返回有序集合指定区间内的成员
> 其中成员的位置按分数值递增(从小到大)来排序。
> 具有相同分数值的成员按字典序(lexicographical order )来排列。
> 如果你需要成员按 值递减(从大到小)来排列，请使用 ZREVRANGE 命令。
> 下标参数 start 和 stop 都以 0 为底，也就是说，以 0 表示有序集第一个成员，以 1 表示有序集第二个成员，以此类推。
> 你也可以使用负数下标，以 -1 表示最后一个成员， -2 表示倒数第二个成员，以此类推。
```redis
127.0.0.1:6379> ZADD salary 3500 "jack" 5000 "tom" 10086 "boss"
(integer) 3
127.0.0.1:6379> ZRANGE salary 0 -1 WITHSCORES
1) "jack"
2) "3500"
3) "tom"
4) "5000"
5) "boss"
6) "10086"
127.0.0.1:6379> ZRANGE salary 1 2 WITHSCORES
1) "tom"
2) "5000"
3) "boss"
4) "10086"
127.0.0.1:6379> ZRANGE salary 0 200000 WITHSCORES
1) "jack"
2) "3500"
3) "tom"
4) "5000"
5) "boss"
6) "10086"
127.0.0.1:6379> ZRANGE salary 200000 3000000 WITHSCORES
(empty list or set)
```
### 1.6.8 ZRANGEBYLEX key min max [LIMIT offset count]
`ZRANGEBYLEX key min max [LIMIT offset count]`
> 通过字典区间返回有序集合的成员
```redis
127.0.0.1:6379> ZRANGEBYLEX myzset - [c
1) "a"
2) "b"
3) "c"
127.0.0.1:6379> ZRANGEBYLEX myzset - (c
1) "a"
2) "b"
127.0.0.1:6379> ZRANGEBYLEX myzset [aaa (g
1) "b"
2) "c"
3) "d"
4) "e"
5) "f"
127.0.0.1:6379> ZRANGEBYLEX myzset [a (g
1) "a"
2) "b"
3) "c"
4) "d"
5) "e"
6) "f"
```
### 1.6.9 ZRANGEBYSCORE key min max [WITHSCORES] [LIMIT]
`ZRANGEBYSCORE key min max [WITHSCORES] [LIMIT offset count]`
> 通过分数返回有序集合指定区间内的成员
> Zrangebyscore 返回有序集合中指定分数区间的成员列表。有序集成员按分数值递增(从小到大)次序排列。
> 具有相同分数值的成员按字典序来排列(该属性是有序集提供的，不需要额外的计算)。
> 默认情况下，区间的取值使用闭区间 (小于等于或大于等于)，你也可以通过给参数前增加 ( 符号来使用可选的开区间 (小于或大于)
```redis
127.0.0.1:6379> ZADD salary 2500 jack 5000 tom 12000 peter
(integer) 1
127.0.0.1:6379> ZRANGEBYSCORE salary -inf +inf
1) "jack"
2) "tom"
3) "boss"
4) "peter"
127.0.0.1:6379> ZRANGEBYSCORE salary -inf +inf WITHSCORES
1) "jack"
2) "2500"
3) "tom"
4) "5000"
5) "boss"
6) "10086"
7) "peter"
8) "12000"
127.0.0.1:6379> ZRANGEBYSCORE salary -inf 5000 WITHSCORES # 显示工资 <=5000 的所有成员
1) "jack"
2) "2500"
3) "tom"
4) "5000"
127.0.0.1:6379> ZRANGEBYSCORE salary -inf (5000 WITHSCORES # 显示工资 < 5000 的所有成员
1) "jack"
2) "2500"
127.0.0.1:6379> ZRANGEBYSCORE salary (5000 400000 WITHSCORES # 显示工资大于 5000 小于等于 400000 的成员
1) "boss"
2) "10086"
3) "peter"
4) "12000"
```
### 1.6.10 ZRANK key member
`ZRANK key member`
> 返回有序集合中指定成员的索引
> 返回有序集中指定成员的排名。其中有序集成员按分数值递增(从小到大)顺序排列。
```redis
127.0.0.1:6379> ZRANK salary tom
(integer) 1
127.0.0.1:6379> ZRANK salary jack
(integer) 0
```
### 1.6.11 ZREM key member [member ...]
`ZREM key member [member ...]`
> 移除有序集合中的一个或多个成员
> 不存在的成员将被忽略。
> 当 key 存在但不是有序集类型时，返回一个错误。
```redis
127.0.0.1:6379> ZADD page_rank 8 bing.com 9 baidu.com 10 google.com
(integer) 3
127.0.0.1:6379> ZRANGE page_rank 0 -1 WITHSCORES
1) "bing.com"
2) "8"
3) "baidu.com"
4) "9"
5) "google.com"
6) "10"
127.0.0.1:6379> ZREM page_rank google.com # 移除单个元素
(integer) 1
127.0.0.1:6379> ZRANGE page_rank 0 -1 WITHSCORES
1) "bing.com"
2) "8"
3) "baidu.com"
4) "9"
127.0.0.1:6379> ZREM page_rank baidu.com bing.com  ## 移除多个元素
(integer) 2
127.0.0.1:6379> ZRANGE page_rank 0 -1 WITHSCORES
(empty list or set)
127.0.0.1:6379> ZREM page_rank non-exists-element # 移除不存在元素
(integer) 0
```
### 1.6.12 ZREMRANGEBYLEX key min max
`ZREMRANGEBYLEX key min max`
> 移除有序集合中给定的字典区间的所有成员
```redis
127.0.0.1:6379> ZADD myzset 0 foo 0 zap 0 zip 0 ALPHA 0 alpha 0
(integer) 6
127.0.0.1:6379> ZRANGE myzset 0 -1
 1) "ALPHA"
 2) "a"
 3) "aaaa"
 4) "alpha"
 5) "b"
 6) "c"
 7) "d"
 8) "e"
 9) "f"
10) "foo"
11) "g"
12) "zap"
13) "zip"
14) "two"
15) "one"
127.0.0.1:6379> ZREMRANGEBYLEX myzset [alpha [omega
(integer) 8
127.0.0.1:6379> ZRANGE myzset 0 -1
1) "ALPHA"
2) "a"
3) "aaaa"
4) "zap"
5) "zip"
6) "two"
7) "one"
```
### 1.6.13 ZREMRANGEBYRANK key start stop
`ZREMRANGEBYRANK key start stop`
> 移除有序集合中给定的排名区间的所有成员
```redis
127.0.0.1:6379> ZRANGE salary 0 -1
1) "jack"
2) "tom"
3) "boss"
4) "peter"
127.0.0.1:6379> ZREMRANGEBYRANK salary 0 1 # 移除下标 0 至 1 区间内的成员
(integer) 2
127.0.0.1:6379> ZRANGE salary 0 -1 WITHSCORES
1) "boss"
2) "10086"
3) "peter"
4) "12000"
```
### 1.6.14 ZREMRANGEBYSCORE key min max
`ZREMRANGEBYSCORE key min max`
> 移除有序集合中给定的分数区间的所有成员
```redis
127.0.0.1:6379> zadd salary 2000 tom 3500 peter 5000 jack 10086 boss
(integer) 4
127.0.0.1:6379> ZRANGE salary 0 -1 WITHSCORES
1) "tom"
2) "2000"
3) "peter"
4) "3500"
5) "jack"
6) "5000"
7) "boss"
8) "10086"
127.0.0.1:6379> ZREMRANGEBYSCORE salary 1500 3500
(integer) 2
127.0.0.1:6379> ZRANGE salary 0 -1 WITHSCORES
1) "jack"
2) "5000"
3) "boss"
4) "10086"
```
### 1.6.15 ZREVRANGE key start stop [WITHSCORES]
`ZREVRANGE key start stop [WITHSCORES]`
> 返回有序集中指定区间内的成员，通过索引，分数从高到低
> Zrevrange 命令返回有序集中，指定区间内的成员。
> 其中成员的位置按分数值递减(从大到小)来排列。
> 具有相同分数值的成员按字典序的逆序(reverse lexicographical order)排列。
> 除了成员按分数值递减的次序排列这一点外， ZREVRANGE 命令的其他方面和 ZRANGE 命令一样。
```redis
127.0.0.1:6379> zadd salary 2000 tom 3500 peter 5000 jack
(integer) 3
127.0.0.1:6379> ZRANGE salary 0 -1
1) "tom"
2) "peter"
3) "jack"
127.0.0.1:6379> ZREVRANGE salary 0 -1 WITHSCORES
1) "jack"
2) "5000"
3) "peter"
4) "3500"
5) "tom"
6) "2000"
```
### 1.6.16 ZREVRANGEBYSCORE key max min [WITHSCORES]
`ZREVRANGEBYSCORE key max min [WITHSCORES] [LIMIT offset count]`
> 返回有序集中指定分数区间内的成员，分数从高到低排序
> Zrevrangebyscore 返回有序集中指定分数区间内的所有的成员。有序集成员按分数值递减(从大到小)的次序排列。
> 具有相同分数值的成员按字典序的逆序(reverse lexicographical order )排列。
> 除了成员按分数值递减的次序排列这一点外， ZREVRANGEBYSCORE 命令的其他方面和 ZRANGEBYSCORE 命令一样。
```redis
127.0.0.1:6379> del salary
(integer) 1
127.0.0.1:6379> ZADD salary 10086 jack 5000 tom 7500 peter 3500 joe
(integer) 4
127.0.0.1:6379> ZRANGE salary 0  -1
1) "joe"
2) "tom"
3) "peter"
4) "jack"
127.0.0.1:6379> ZREVRANGEBYSCORE salary +inf -inf
1) "jack"
2) "peter"
3) "tom"
4) "joe"
127.0.0.1:6379> ZREVRANGEBYSCORE salary 10000 2000
1) "peter"
2) "tom"
3) "joe"
```
### 1.6.17 ZREVRANK key member
`ZREVRANK key member`
> 返回有序集合中指定成员的排名，有序集成员按分数值递减(从大到小)排序
> Zrevrank 命令返回有序集中成员的排名。其中有序集成员按分数值递减(从大到小)排序。
> 排名以 0 为底，也就是说， 分数值最大的成员排名为 0 。
> 使用 ZRANK 命令可以获得成员按分数值递增(从小到大)排列的排名。
```redis
127.0.0.1:6379> ZRANGE salary 0 -1 WITHSCORES
1) "joe"
2) "3500"
3) "tom"
4) "5000"
5) "peter"
6) "7500"
7) "jack"
8) "10086"
127.0.0.1:6379> ZREVRANK salary peter # peter 的工资排第二
(integer) 1
127.0.0.1:6379> ZREVRANK salary jack # jack 的工资最高
(integer) 0
```
### 1.6.18 ZSCORE key member
`ZSCORE key member`
> 返回有序集中，成员的分数值
> 成员的分数值。 如果成员元素不是有序集 key 的成员，或 key 不存在，返回 nil 。
```redis
127.0.0.1:6379> ZRANGE salary 0 -1 WITHSCORES
1) "joe"
2) "3500"
3) "tom"
4) "5000"
5) "peter"
6) "7500"
7) "jack"
8) "10086"
127.0.0.1:6379> ZSCORE salary peter  # 注意返回值是字符串
"7500"
```
### 1.6.19 ZUNIONSTORE destination numkeys key [key ...]
`ZUNIONSTORE destination numkeys key [key ...] [WEIGHTS weight [weight ...]] [AGGREGATE SUM|MIN|MAX]`
> 计算给定的一个或多个有序集的并集，并存储在新的 key 中
> 其中给定 key 的数量必须以 numkeys 参数指定，并将该并集(结果集)储存到 destination 。
> 默认情况下，结果集中某个成员的分数值是所有给定集下该成员分数值之和 。
> 使用 `WEIGHTS` 选项时，可以为各个有序集合输入指定一个乘法系数（Multiplication factor ）。这意味着在将每个有序集合输入中的每个元素的分值传递给聚合函数（Aggregation function）之前，会将该分值乘以对应的系数。当未给定 WEIGHTS 选项时，乘法系数默认为 1。
> 使用 `AGGREGATE` 选项时，可以指定并集运算结果的聚合方式。该选项默认值为 `SUM`，即将输入中所有存在该元素的集合中对应的分值全部加一起。当选项被设置为 `MIN` 或 `MAX` 任意值时，结果集合将保存输入中所有存在该元素的集合中对应的分值的最小或最大值。
> 如果目标键 destination 已经存在，将会被覆盖
```redis
127.0.0.1:6379> ZADD zset1 2 "two" 1 "one"
(integer) 2
127.0.0.1:6379> ZADD zset2 1 "one" 2 "two" 3 "three"
(integer) 3
127.0.0.1:6379> ZUNIONSTORE out 2 zset1 zset2 WEIGHTS 2 3   # (1*2+1*3) # (2*2+2*3) # (3*3)
(integer) 3
127.0.0.1:6379> ZRANGE out 0 -1 WITHSCORES
1) "one"
2) "5"
3) "three"
4) "9"
5) "two"
6) "10"
```
### 1.6.20 ZSCAN key cursor [MATCH pattern] [COUNT count]
`ZSCAN key cursor [MATCH pattern] [COUNT count]`
> 迭代有序集合中的元素（包括元素成员和元素分值）
> - cursor - 游标。
> - pattern - 匹配的模式。
> - count - 指定从数据集里返回多少元素，默认值为 10 。
```redis
127.0.0.1:6379> ZADD site 1 "Google" 2 "Runoob" 3 "Taobao" 4 "Weibo"
(integer) 4
127.0.0.1:6379> ZSCAN site 0 match "R*"
1) "0"
2) 1) "Runoob"
   2) "2"
127.0.0.1:6379> ZSCAN site 0 match *o*
1) "0"
2) 1) "Google"
   2) "1"
   3) "Runoob"
   4) "2"
   5) "Taobao"
   6) "3"
   7) "Weibo"
   8) "4"
```
## 1.7 Redis HyperLogLog


> Redis HyperLogLog 是用来做基数统计的算法，HyperLogLog 的优点是，在输入元素的数量或者体积非常非常大时，计算基数所需的空间总是固定 的、并且是很小的。
> 在 Redis 里面，每个 HyperLogLog 键只需要花费 12 KB 内存，就可以计算接近 2^64 个不同元素的基 数。这和计算基数时，元素越多耗费内存就越多的集合形成鲜明对比。
> 但是，因为 HyperLogLog 只会根据输入元素来计算基数，而不会储存输入元素本身，所以 HyperLogLog 不能像集合那样，返回输入的各个元素。
### 1.7.1 PFADD key element [element ...]
`PFADD key element [element ...]`
> 添加指定元素到 HyperLogLog 中。
```redis
127.0.0.1:6379> del mykey
(integer) 1
127.0.0.1:6379> PFADD mykey a b c d e f g h i j
(integer) 1
127.0.0.1:6379> PFCOUNT mykey
(integer) 10
```
### 1.7.2 PFCOUNT key [key ...]
`PFCOUNT key [key ...]`
> 返回给定 HyperLogLog 的基数估算值。
```redis
127.0.0.1:6379> PFADD hll foo bar zap # 3
(integer) 1
127.0.0.1:6379> PFADD hll zap zap zap # 3
(integer) 0
127.0.0.1:6379> PFADD hll foo bar     # 3
(integer) 0
127.0.0.1:6379> PFCOUNT hll           # 3
(integer) 3
127.0.0.1:6379> PFADD some-other-hll 1 2 3
(integer) 1
127.0.0.1:6379> PFCOUNT hll some-other-hll
(integer) 6
```
### 1.7.3 PFMERGE destkey sourcekey [sourcekey ...]
> 将多个 HyperLogLog 合并为一个 HyperLogLog
> 合并后的 HyperLogLog 的基数估算值是通过对所有 给定 HyperLogLog 进行并集计算得出的。
```redis
127.0.0.1:6379> PFADD hll1 foo bar zap a
(integer) 1
127.0.0.1:6379> PFCOUNT hll1
(integer) 4
127.0.0.1:6379> PFADD hll2 a b c foo
(integer) 1
127.0.0.1:6379> PFCOUNT hll2
(integer) 4
127.0.0.1:6379> PFMERGE hll3 hll1 hll2
OK
127.0.0.1:6379> PFCOUNT hll3
(integer) 6
```
## 1.8 Redis 发布订阅


> 是一种消息通信模式：发送者 (pub) 发送消息，订阅者 (sub) 接收消息。
> Redis 客户端可以订阅任意数量的频道。
### 1.8.1 PSUBSCRIBE pattern [pattern ...]
`PSUBSCRIBE pattern [pattern ...]`
> 订阅一个或多个符合给定模式的频道。
> 每个模式以 * 作为匹配符，比如 it* 匹配所有以 it 开头的频道( it.news 、 it.blog 、 it.tweets 等等)。
### 1.8.2 PUBSUB subcommand [argument [argument ...]]
`PUBSUB <subcommand> [argument [argument ...]]`
> 查看订阅与发布系统状态。
### 1.8.3 PUBLISH channel message
`PUBLISH channel message`
将信息发送到指定的频道。
### 1.8.4 PUNSUBSCRIBE [pattern [pattern ...]]
`PUNSUBSCRIBE [pattern [pattern ...]]`
退订所有给定模式的频道。
### 1.8.5 SUBSCRIBE channel [channel ...]
`SUBSCRIBE channel [channel ...]`
订阅给定的一个或多个频道的信息。
### 1.8.6 UNSUBSCRIBE [channel [channel ...]]
`UNSUBSCRIBE channel [channel ...]`
指退订给定的频道。
## 1.9 Redis 事务


### 1.9.0 Redis事务
> Redis 事务可以一次执行多个命令， 并且带有以下三个重要的保证：
- 批量操作在发送 EXEC 命令前被放入队列缓存。
- 收到 EXEC 命令后进入事务执行，事务中任意命令执行失败，其余的命令依然被执行。
- 在事务执行过程，其他客户端提交的命令请求不会插入到事务执行命令序列中。

> 一个事务从开始到执行会经历以下三个阶段：
- 开始事务。
- 命令入队。
- 执行事务。

> 单个 Redis 命令的执行是原子性的，但 Redis 没有在事务上增加任何维持原子性的机制，所以 Redis 事务的执行并不是原子性的。
> 事务可以理解为一个打包的批量执行脚本，但批量指令并非原子化的操作，中间某条指令的失败不会导致前面已做指令的回滚，也不会造成后续的指令不做。

### 1.9.1 事务命令
#### 1.9.1.1 DISCARD
> 取消事务，放弃执行事务块内的所有命令。
```redis
127.0.0.1:6379> MULTI
OK
127.0.0.1:6379> PING
QUEUED
127.0.0.1:6379> SET greeting "hello"
QUEUED
127.0.0.1:6379> DISCARD
OK
127.0.0.1:6379> get greeting
(nil)
```
#### 1.9.1.2 EXEC
> 执行所有事务块内的命令。

```redis
127.0.0.1:6379> MULTI
OK
127.0.0.1:6379> get user_id
QUEUED
127.0.0.1:6379> INCR user_id
QUEUED
127.0.0.1:6379> INCR user_id
QUEUED
127.0.0.1:6379> INCR user_id
QUEUED
127.0.0.1:6379> PING
QUEUED
127.0.0.1:6379> EXEC
1) (nil)
2) (integer) 1
3) (integer) 2
4) (integer) 3
5) PONG
```

> 监视 key ，且事务成功执行

```redis
127.0.0.1:6379> WATCH lock lock_times
OK
127.0.0.1:6379> MULTI
OK
127.0.0.1:6379> SET lock "huangz"
QUEUED
127.0.0.1:6379> INCR lock_times
QUEUED
127.0.0.1:6379> EXEC
1) OK
2) (integer) 1
127.0.0.1:6379> get lock
"huangz"
127.0.0.1:6379> get lock_times
"1"
```

> 监视 key ，且事务被打断，被其他redis_cli 修改

```redis
127.0.0.1:6379> WATCH lock lock_times
OK
127.0.0.1:6379> MULTI
OK
127.0.0.1:6379> INCR lock_times
QUEUED
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>another redis-cli
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>127.0.0.1:6379> SET lock "joe"
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>OK
127.0.0.1:6379> EXEC
(nil)
127.0.0.1:6379> get lock
"joe"
```

#### 1.9.1.3 MULTI
> 标记一个事务块的开始。
> 事务块内的多条命令会按照先后顺序被放进一个队列当中，最后由 EXEC 命令原子性(atomic)地执行
>  见 1.9.1.2 EXEC
#### 1.9.1.4 UNWATCH
> 取消 WATCH 命令对所有 key 的监视。
#### 1.9.1.5 WATCH key [key ...]
监视一个(或多个) key ，如果在事务执行之前这个(或这些) key 被其他命令所改动，那么事务将被打断。

## 1.10 Redis 脚本


> lua 解释器来执行脚本；
`EVAL script numkeys key [key ...] arg [arg ...]`
### 1.10.1 EVAL script numkeys key [key ...] arg [arg ...]
`EVAL script numkeys key [key ...] arg [arg ...] `
> 执行 Lua 脚本。
- `script`： 参数是一段 Lua 5.1 脚本程序。脚本不必(也不应该)定义为一个 Lua 函数。
- `numkeys`： 用于指定键名参数的个数。
- `key [key ...]`： 从 EVAL 的第三个参数开始算起，表示在脚本中所用到的那些 Redis 键(key)，这些键名参数可以在 Lua 中通过全局变量 KEYS 数组，用 1 为基址的形式访问( KEYS[1] ， KEYS[2] ，以此类推)。
- `arg [arg ...]`： 附加参数，在 Lua 中通过全局变量 ARGV 数组访问，访问的形式和 KEYS 变量类似( ARGV[1] 、 ARGV[2] ，诸如此类)。
```redis
127.0.0.1:6379> eval "return {KEYS[1],KEYS[2],ARGV[1],ARGV[2]}" 2 key1 key2 first second
1) "key1"
2) "key2"
3) "first"
4) "second"
```
### 1.10.2 EVALSHA sha1 numkeys key [key ...] arg [arg ...]
`EVALSHA sha1 numkeys key [key ...] arg [arg ...] `
> Evalsha 命令根据给定的 sha1 校验码，执行缓存在服务器中的脚本。
> 将脚本缓存到服务器的操作可以通过 SCRIPT LOAD 命令进行。
> 这个命令的其他地方，比如参数的传入方式，都和 EVAL 命令一样。
- `sha1` ： 通过 SCRIPT LOAD 生成的 sha1 校验码。
- `numkeys`： 用于指定键名参数的个数。
- `key [key ...]`： 从 EVAL 的第三个参数开始算起，表示在脚本中所用到的那些 Redis 键(key)，这些键名参数可以在 Lua 中通过全局变量 KEYS 数组，用 1 为基址的形式访问( KEYS[1] ， KEYS[2] ，以此类推)。
- `arg [arg ...]`： 附加参数，在 Lua 中通过全局变量 ARGV 数组访问，访问的形式和 KEYS 变量类似( ARGV[1] 、 ARGV[2] ，诸如此类)。
```redis
127.0.0.1:6379> SCRIPT LOAD "return 'hello moto'"
"232fd51614574cf0867b83d384a5e898cfd24e5a"
127.0.0.1:6379> EVALSHA "232fd51614574cf0867b83d384a5e898cfd24e5a" 0
"hello moto"
```
### 1.10.3 SCRIPT EXISTS script [script ...]
`SCRIPT EXISTS sha1 [sha1 ...]`
> 查看指定的脚本是否已经被保存在缓存当中。
> 一个列表，包含 0 和 1 ，前者表示脚本不存在于缓存，后者表示脚本已经在缓存里面了。
> 列表中的元素和给定的 SHA1 校验和保持对应关系，比如列表的第三个元素的值就表示第三个 SHA1 校验和所指定的脚本在缓存中的状态。
```redis
127.0.0.1:6379> SCRIPT LOAD "return 'hello moto'"
"232fd51614574cf0867b83d384a5e898cfd24e5a"
127.0.0.1:6379> EVALSHA "232fd51614574cf0867b83d384a5e898cfd24e5a" 0
"hello moto"
127.0.0.1:6379> SCRIPT EXISTS 232fd51614574cf0867b83d384a5e898cfd24e5a
1) (integer) 1
127.0.0.1:6379> SCRIPT FLUSH
OK
127.0.0.1:6379> SCRIPT EXISTS 232fd51614574cf0867b83d384a5e898cfd24e5a
1) (integer) 0
```
### 1.10.4 SCRIPT FLUSH
`SCRIPT FLUSH`
从脚本缓存中移除所有lua脚本缓存。
### 1.10.5 SCRIPT KILL
> Script kill 命令用于杀死当前正在运行的 Lua 脚本，当且仅当这个脚本没有执行过任何写操作时，这个命令才生效。
> 这个命令主要用于终止运行时间过长的脚本，比如一个因为 BUG 而发生无限循环的脚本。
> SCRIPT KILL 执行之后，当前正在运行的脚本会被杀死，执行这个脚本的客户端会从 EVAL 命令的阻塞当中退出，并收到一个错误作为返回值
```redis
127.0.0.1:6379> EVAL "while (true) do print('nsafmm') end" 0
(error) ERR Error running script (call to f_bdc4f7522bd3952f995db8cf04e05d3285d78b06): @user_script:1: Script killed by user with SCRIPT KILL...
(5.62s)
```

```redis
127.0.0.1:6379> SCRIPT KILL
OK
(4.07s)
```
### 1.10.6 SCRIPT LOAD script
`SCRIPT LOAD script`
> Script Load 命令用于将脚本 script 添加到脚本缓存中，但并不立即执行这个脚本。
> EVAL 命令也会将脚本添加到脚本缓存中，但是它会立即对输入的脚本进行求值。
> 如果给定的脚本已经在缓存里面了，那么不执行任何操作。
> 在脚本被加入到缓存之后，通过 EVALSHA 命令，可以使用脚本的 SHA1 校验和来调用这个脚本。
> 脚本可以在缓存中保留无限长的时间，直到执行 SCRIPT FLUSH 为止。
```redis
127.0.0.1:6379> SCRIPT LOAD "return 1"
"e0e1f9fabfc9d4800c877a703b823ac0578ff8db"
```
## 1.11 Redis 连接


### 1.11.1 AUTH password
> 验证密码是否正确
```redis
redis 127.0.0.1:6379> AUTH PASSWORD
(error) ERR Client sent AUTH, but no password is set
redis 127.0.0.1:6379> CONFIG SET requirepass "mypass"
OK
redis 127.0.0.1:6379> AUTH mypass
Ok
```
### 1.11.2 ECHO message
`ECHO message`
> 打印字符串
```redis
redis 127.0.0.1:6379> ECHO "Hello World"
"Hello World"
```
### 1.11.3 PING
查看服务是否运行
### 1.11.4 QUIT
关闭当前连接
### 1.11.5 SELECT index
切换到指定的数据库
## 1.12 Redis 服务器


### 1.12.1 BGREWRITEAOF
> 异步执行一个 AOF（AppendOnly File） 文件重写操作
> Bgrewriteaof 命令用于异步执行一个 AOF（AppendOnly File） 文件重写操作。重写会创建一个当前 AOF 文件的体积优化版本。
> 即使 Bgrewriteaof 执行失败，也不会有任何数据丢失，因为旧的 AOF 文件在 Bgrewriteaof 成功之前不会被修改。
> 注意：从 Redis 2.4 开始， AOF 重写由 Redis 自行触发， BGREWRITEAOF 仅仅用于手动触发重写操作。
```redis
127.0.0.1:6379> BGREWRITEAOF
Background append only file rewriting started
```

```redis
[9420] 11 Nov 17:36:49.514 * Background append only file rewriting started by pid 10996
[9420] 11 Nov 17:36:49.717 * AOF rewrite child asks to stop sending diffs.
[9420] 11 Nov 17:36:49.817 # fork operation complete
[9420] 11 Nov 17:36:49.817 * Background AOF rewrite terminated with success
[9420] 11 Nov 17:36:49.818 * Residual parent diff successfully flushed to the rewritten AOF (0.00 MB)
[9420] 11 Nov 17:36:49.821 * Background AOF rewrite finished successfully
```
### 1.12.2 BGSAVE
> Bgsave 命令用于在后台异步保存当前数据库的数据到磁盘。
> BGSAVE 命令执行之后立即返回 OK ，然后 Redis fork 出一个新子进程，原来的 Redis 进程(父进程)继续处理客户端请求，而子进程则负责将数据保存到磁盘，然后退出。
```redis
127.0.0.1:6379> BGSAVE
Background saving started
```

```redis
[9420] 11 Nov 17:38:50.136 # fork operation complete
[9420] 11 Nov 17:38:50.136 * Background saving terminated with success
```
### 1.12.3 CLIENT KILL [ip:port] [ID client-id]
> 关闭客户端连接
```redis
# 列出所有已连接客户端
127.0.0.1:6379> CLIENT LIST
id=15 addr=127.0.0.1:64570 fd=18 name= age=9 idle=9 flags=N db=0 sub=0 psub=0 multi=-1 qbuf=0 qbuf-free=0 obl=0 oll=0 omem=0 events=r cmd=client
id=16 addr=127.0.0.1:64571 fd=15 name= age=0 idle=0 flags=N db=0 sub=0 psub=0 multi=-1 qbuf=0 qbuf-free=32768 obl=0 oll=0 omem=0 events=r cmd=client
# 杀死当前客户端的连接
127.0.0.1:6379> CLIENT KILL 127.0.0.1:64571
OK
# 之前的连接已经被关闭，CLI 客户端又重新建立了连接
# 之前的端口是 43501 ，现在是 43504
127.0.0.1:6379> CLIENT LIST
id=15 addr=127.0.0.1:64570 fd=18 name= age=29 idle=29 flags=N db=0 sub=0 psub=0 multi=-1 qbuf=0 qbuf-free=0 obl=0 oll=0 omem=0 events=r cmd=client
id=17 addr=127.0.0.1:64575 fd=12 name= age=0 idle=0 flags=N db=0 sub=0 psub=0 multi=-1 qbuf=0 qbuf-free=32768 obl=0 oll=0 omem=0 events=r cmd=client
```
### 1.12.4 CLIENT LIST
> 获取连接到服务器的客户端连接列表
#### 1.12.4.1 返回值
> 命令返回多行字符串，这些字符串按以下形式被格式化：
> 每个已连接客户端对应一行（以 LF 分割）
> 每行字符串由一系列 属性=值 形式的域组成，每个域之间以空格分开
#### 1.12.4.2 域
##### 1.12.4.2.1 以下是域的含义：
- addr ： 客户端的地址和端口
- fd ： 套接字所使用的文件描述符
- age ： 以秒计算的已连接时长
- idle ： 以秒计算的空闲时长
- flags ： 客户端 flag
- db ： 该客户端正在使用的数据库 ID
- sub ： 已订阅频道的数量
- psub ： 已订阅模式的数量
- multi ： 在事务中被执行的命令数量
- qbuf ： 查询缓冲区的长度（字节为单位， 0 表示没有分配查询缓冲区）
- qbuf-free ： 查询缓冲区剩余空间的长度（字节为单位， 0 表示没有剩余空间）
- obl ： 输出缓冲区的长度（字节为单位， 0 表示没有分配输出缓冲区）
- oll ： 输出列表包含的对象数量（当输出缓冲区没有剩余空间时，命令回复会以字符串对象的形式被入队到这个队列里）
- omem ： 输出缓冲区和输出列表占用的内存总量
- events ： 文件描述符事件
- cmd ： 最近一次执行的命令
##### 1.12.4.2.2 客户端 flag 可以由以下部分组成：
- O ： 客户端是 MONITOR 模式下的附属节点（slave）
- S ： 客户端是一般模式下（normal）的附属节点
- M ： 客户端是主节点（master）
- x ： 客户端正在执行事务
- b ： 客户端正在等待阻塞事件
- i ： 客户端正在等待 VM I/O 操作（已废弃）
- d ： 一个受监视（watched）的键已被修改， EXEC 命令将失败
- c : 在将回复完整地写出之后，关闭链接
- u : 客户端未被阻塞（unblocked）
- A : 尽可能快地关闭连接
- N : 未设置任何 flag
##### 1.12.4.2.3 文件描述符事件可以是：
- r : 客户端套接字（在事件 loop 中）是可读的（readable）
- w : 客户端套接字（在事件 loop 中）是可写的（writeable）
```redis

```
### 1.12.5 CLIENT GETNAME
> 获取连接的名称
> Client Getname 命令用于返回 CLIENT SETNAME 命令为连接设置的名字。
> 因为新创建的连接默认是没有名字的， 对于没有名字的连接， CLIENT GETNAME 返回空白回复。
```redis
# 新连接默认没有名字
redis 127.0.0.1:6379> CLIENT GETNAME
(nil)
# 设置名字
redis 127.0.0.1:6379> CLIENT SETNAME hello-world-connection
OK
# 返回名字
redis 127.0.0.1:6379> CLIENT GETNAME
"hello-world-connection"
```
### 1.12.6 CLIENT PAUSE timeout
> 在指定时间内终止运行来自客户端的命令
> Client Pause 命令用于阻塞客户端命令一段时间（以毫秒计）。
```redis
127.0.0.1:6379> CLIENT PAUSE 5000
OK
127.0.0.1:6379> zrange zset2 0 -1 WITHSCORES
1) "one"
2) "1"
3) "two"
4) "2"
5) "three"
6) "3"
(2.90s)
```
### 1.12.7 CLIENT SETNAME connection-name
> 设置当前连接的名称
```redis
redis 127.0.0.1:6379> CLIENT SETNAME hello-world-connection
OK
127.0.0.1:6379> CLIENT GETNAME
"hello-world-connection"
127.0.0.1:6379> CLIENT LIST
id=15 addr=127.0.0.1:64570 fd=18 name= age=11066 idle=11066 flags=N db=0 sub=0 psub=0 multi=-1 qbuf=0 qbuf-free=0 obl=0 oll=0 omem=0 events=r cmd=client
id=17 addr=127.0.0.1:64575 fd=12 name=hello-world-connection age=11037 idle=0 flags=N db=0 sub=0 psub=0 multi=-1 qbuf=0 qbuf-free=32768 obl=0 oll=0 omem=0 events=r cmd=client
CLIENT SETNAME ""
```
### 1.12.8 CLUSTER SLOTS
`CLUSTER SLOTS `
> 获取集群节点的映射数组
> IP/端口嵌套的列表数组形式展示。
### 1.12.9 COMMAND
> 获取 Redis 命令详情数组
> 用于返回所有的Redis命令的详细信息，以数组形式展示
```redis
 33) 1) "zscan"
     2) (integer) -3
     3) 1) readonly
        2) random
     4) (integer) 1
     5) (integer) 1
     6) (integer) 1
...
171) 1) "randomkey"
     2) (integer) 1
     3) 1) readonly
        2) random
     4) (integer) 0
     5) (integer) 0
     6) (integer) 0
172) 1) "restore-asking"
     2) (integer) -4
     3) 1) write
        2) denyoom
        3) asking
     4) (integer) 1
     5) (integer) 1
     6) (integer) 1
```
### 1.12.10 COMMAND COUNT
> 获取 Redis 命令总数
```redis
127.0.0.1:6379> COMMAND COUNT
(integer) 172
```
### 1.12.11 COMMAND GETKEYS
`COMMAND GETKEYS`
> 获取给定命令的所有键
```redis

```
### 1.12.12 TIME
> 返回当前服务器时间
### 1.12.13 COMMAND INFO command-name [command-name ...]
`COMMAND INFO command-name [command-name ...] `
> 获取指定 Redis 命令描述的数组
```redis
127.0.0.1:6379> COMMAND INFO get set eval
1) 1) "get"
   2) (integer) 2
   3) 1) readonly
      2) fast
   4) (integer) 1
   5) (integer) 1
   6) (integer) 1
2) 1) "set"
   2) (integer) -3
   3) 1) write
      2) denyoom
   4) (integer) 1
   5) (integer) 1
   6) (integer) 1
3) 1) "eval"
   2) (integer) -3
   3) 1) noscript
      2) movablekeys
   4) (integer) 0
   5) (integer) 0
   6) (integer) 0
127.0.0.1:6379> COMMAND INFO foo evalsha config bar
1) (nil)
2) 1) "evalsha"
   2) (integer) -3
   3) 1) noscript
      2) movablekeys
   4) (integer) 0
   5) (integer) 0
   6) (integer) 0
3) 1) "config"
   2) (integer) -2
   3) 1) admin
      2) loading
      3) stale
   4) (integer) 0
   5) (integer) 0
   6) (integer) 0
4) (nil)
```
### 1.12.14 CONFIG GET parameter
`CONFIG GET parameter`
> 获取指定配置参数的值
```redis
127.0.0.1:6379> config get *max-*-entries*
1) "hash-max-ziplist-entries"
2) "512"
3) "set-max-intset-entries"
4) "512"
5) "zset-max-ziplist-entries"
6) "128"
```
### 1.12.15 CONFIG REWRITE
`CONFIG REWRITE parameter`
> 对启动 Redis 服务器时所指定的 redis.conf 配置文件进行改写
> CONFIG SET 命令可以对服务器的当前配置进行修改， 而修改后的配置可能和 redis.conf 文件中所描述的配置不一样， CONFIG REWRITE 的作用就是通过尽可能少的修改， 将服务器当前所使用的配置记录到 redis.conf 文件中。
```redis
127.0.0.1:6379> CONFIG GET appendonly           # appendonly 处于关闭状态
1) "appendonly"
2) "no"
127.0.0.1:6379> CONFIG SET appendonly yes       # 打开 appendonly
OK
127.0.0.1:6379> CONFIG GET appendonly
1) "appendonly"
2) "yes"
127.0.0.1:6379> CONFIG REWRITE                  # 将 appendonly 的修改写入到 redis.conf 中
OK
```
> 重写后的 redis.conf 文件中的 appendonly 选项将被改写：
```redis
# ... 其他选项
appendonly yes
# ... 其他选项
```
### 1.12.16 CONFIG SET parameter value
`CONFIG Set parameter value`
> 修改 redis 配置参数，无需重启
>  Config Set 命令可以动态地调整 Redis 服务器的配置(configuration)而无须重启。
> 可以使用它修改配置参数，或者改变 Redis 的持久化(Persistence)方式。
```redis
redis 127.0.0.1:6379> CONFIG GET slowlog-max-len
1) "slowlog-max-len"
2) "1024"
redis 127.0.0.1:6379> CONFIG SET slowlog-max-len 10086
OK
redis 127.0.0.1:6379> CONFIG GET slowlog-max-len
1) "slowlog-max-len"
2) "10086"
```
### 1.12.17 CONFIG RESETSTAT
`CONFIG RESETSTAT`
> 重置 INFO 命令中的某些统计数据
> Config Resetstat 命令用于重置 INFO 命令中的某些统计数据，包括：
- Keyspace hits (键空间命中次数)
- Keyspace misses (键空间不命中次数)
- Number of commands processed (执行命令的次数)
- Number of connections received (连接服务器的次数)
- Number of expired keys (过期key的数量)
- Number of rejected connections (被拒绝的连接数量)
- Latest fork(2) time(最后执行 fork(2) 的时间)
- The aof_delayed_fsync counter(aof_delayed_fsync 计数器的值)
### 1.12.18 DBSIZE
> 返回当前数据库的 key 的数量
```redis
127.0.0.1:6379> DBSIZE
(integer) 135
127.0.0.1:6379> set new_key "hello"
OK
127.0.0.1:6379> DBSIZE
(integer) 136
```
### 1.12.19 DEBUG OBJECT key
`DEBUG OBJECT key`
> 获取 key 的调试信息
> 当 key 存在时，返回有关信息。 当 key 不存在时，返回一个错误。
```redis
127.0.0.1:6379> DEBUG object my_key
(error) ERR no such key
127.0.0.1:6379> DEBUG object zset2
Value at:000007E0C4CE4790 refcount:1 encoding:ziplist serializedlength:35 lru:11324148 lru_seconds_idle:87592
```
### 1.12.20 DEBUG SEGFAULT
> 让 Redis 服务崩溃
> Debug Segfault 命令执行一个非法的内存访问从而让 Redis 崩溃，仅在开发时用于 BUG 调试。
```redis

```
### 1.12.21 FLUSHALL
> 删除所有数据库的所有key
> 清空整个 Redis 服务器的数据(删除所有数据库的所有 key )。
```redis
redis 127.0.0.1:6379> DBSIZE            # 0 号数据库的 key 数量
(integer) 9
redis 127.0.0.1:6379> SELECT 1          # 切换到 1 号数据库
OK
redis 127.0.0.1:6379> DBSIZE         # 1 号数据库的 key 数量
(integer) 6
redis 127.0.0.1:6379> flushall       # 清空所有数据库的所有 key
OK
redis 127.0.0.1:6379> DBSIZE         # 不但 1 号数据库被清空了
(integer) 0
redis 127.0.0.1:6379> SELECT 0       # 0 号数据库(以及其他所有数据库)也一样
OK
redis 127.0.0.1:6379> DBSIZE
(integer) 0
```
### 1.12.22 FLUSHDB
> 删除当前数据库的所有key
> 用于清空当前数据库中的所有 key。
```redis
redis 127.0.0.1:6379> DBSIZE    # 清空前的 key 数量
(integer) 4
redis 127.0.0.1:6379> FLUSHDB
OK
redis 127.0.0.1:6379> DBSIZE    # 清空后的 key 数量
(integer) 0
```
### 1.12.23 INFO [section]
> 获取 Redis 服务器的各种信息和统计数值
> 以一种易于理解和阅读的格式，返回关于 Redis 服务器的各种信息和统计数值。
> 通过给定可选的参数 section ，可以让命令只返回某一部分的信息：
#### 1.12.23.1 server : 一般 Redis 服务器信息，
> 包含以下域：
- redis_version : Redis 服务器版本
- redis_git_sha1 : Git SHA1
- redis_git_dirty : Git dirty flag
- os : Redis 服务器的宿主操作系统
- arch_bits : 架构（32 或 64 位）
- multiplexing_api : Redis 所使用的事件处理机制
- gcc_version : 编译 Redis 时所使用的 GCC 版本
- process_id : 服务器进程的 PID
- run_id : Redis 服务器的随机标识符（用于 Sentinel 和集群）
- tcp_port : TCP/IP 监听端口
- uptime_in_seconds : 自 Redis 服务器启动以来，经过的秒数
- uptime_in_days : 自 Redis 服务器启动以来，经过的天数
- lru_clock : 以分钟为单位进行自增的时钟，用于 LRU 管理
#### 1.12.23.2 clients : 已连接客户端信息，
> 包含以下域：
- connected_clients : 已连接客户端的数量（不包括通过从属服务器连接的客户端）
- client_longest_output_list : 当前连接的客户端当中，最长的输出列表
- client_longest_input_buf : 当前连接的客户端当中，最大输入缓存
- blocked_clients : 正在等待阻塞命令（BLPOP、BRPOP、BRPOPLPUSH）的客户端的数量
#### 1.12.23.3 memory : 内存信息，
> 包含以下域：
- used_memory : 由 Redis 分配器分配的内存总量，以字节（byte）为单位
- used_memory_human : 以人类可读的格式返回 Redis 分配的内存总量
- used_memory_rss : 从操作系统的角度，返回 Redis 已分配的内存总量（俗称常驻集大小）。这个值和 top 、 ps 等命令的输出一致。
- used_memory_peak : Redis 的内存消耗峰值（以字节为单位）
- used_memory_peak_human : 以人类可读的格式返回 Redis 的内存消耗峰值
- used_memory_lua : Lua 引擎所使用的内存大小（以字节为单位）
- mem_fragmentation_ratio : used_memory_rss 和 used_memory 之间的比率
- mem_allocator : 在编译时指定的， Redis 所使用的内存分配器。可以是 libc 、 jemalloc 或者 tcmalloc 。
> 在理想情况下， used_memory_rss 的值应该只比 used_memory 稍微高一点儿。
> 当 rss > used ，且两者的值相差较大时，表示存在（内部或外部的）内存碎片。
> 内存碎片的比率可以通过 mem_fragmentation_ratio 的值看出。
> 当 used > rss 时，表示 Redis 的部分内存被操作系统换出到交换空间了，在这种情况下，操作可能会产生明显的延迟。
> 当 Redis 释放内存时，分配器可能会，也可能不会，将内存返还给操作系统。
> 如果 Redis 释放了内存，却没有将内存返还给操作系统，那么 used_memory 的值可能和操作系统显示的 Redis 内存占用并不一致。
> 查看 used_memory_peak 的值可以验证这种情况是否发生。
persistence : RDB 和 AOF 的相关信息
#### 1.12.23.4 persistence : RDB 和 AOF 的相关信息
#### 1.12.23.5 stats : 一般统计信息
#### 1.12.23.6 replication : 主/从复制信息
#### 1.12.23.7 cpu : CPU 计算量统计信息
#### 1.12.23.8 commandstats : Redis 命令统计信息
#### 1.12.23.9 cluster : Redis 集群信息
#### 1.12.23.10 keyspace : 数据库相关的统计信息

```redis
127.0.0.1:6379> INFO
# Server
redis_version:3.2.100
redis_git_sha1:00000000
redis_git_dirty:0
redis_build_id:dd26f1f93c5130ee
redis_mode:standalone
os:Windows
arch_bits:64
multiplexing_api:WinSock_IOCP
process_id:11996
run_id:775ea0bbf42315d6bc62259ce50c10e9206d7ac1
tcp_port:6379
uptime_in_seconds:431
uptime_in_days:0
hz:10
lru_clock:11412407
executable:C:\SunGards\ks_new\src\trade\tools\Redis_安装包和基础文档\redis直接运行包\redis-server.exe
config_file:

# Clients
connected_clients:1
client_longest_output_list:0
client_biggest_input_buf:0
blocked_clients:0

# Memory
used_memory:735416
used_memory_human:718.18K
used_memory_rss:697504
used_memory_rss_human:681.16K
used_memory_peak:735416
used_memory_peak_human:718.18K
total_system_memory:0
total_system_memory_human:0B
used_memory_lua:37888
used_memory_lua_human:37.00K
maxmemory:0
maxmemory_human:0B
maxmemory_policy:noeviction
mem_fragmentation_ratio:0.95
mem_allocator:jemalloc-3.6.0

# Persistence
loading:0
rdb_changes_since_last_save:0
rdb_bgsave_in_progress:0
rdb_last_save_time:1605247496
rdb_last_bgsave_status:ok
rdb_last_bgsave_time_sec:-1
rdb_current_bgsave_time_sec:-1
aof_enabled:0
aof_rewrite_in_progress:0
aof_rewrite_scheduled:0
aof_last_rewrite_time_sec:-1
aof_current_rewrite_time_sec:-1
aof_last_bgrewrite_status:ok
aof_last_write_status:ok

# Stats
total_connections_received:1
total_commands_processed:1
instantaneous_ops_per_sec:0
total_net_input_bytes:31
total_net_output_bytes:5896072
instantaneous_input_kbps:0.00
instantaneous_output_kbps:0.00
rejected_connections:0
sync_full:0
sync_partial_ok:0
sync_partial_err:0
expired_keys:0
evicted_keys:0
keyspace_hits:0
keyspace_misses:0
pubsub_channels:0
pubsub_patterns:0
latest_fork_usec:0
migrate_cached_sockets:0

# Replication
role:master
connected_slaves:0
master_repl_offset:0
repl_backlog_active:0
repl_backlog_size:1048576
repl_backlog_first_byte_offset:0
repl_backlog_histlen:0

# CPU
used_cpu_sys:0.12
used_cpu_user:0.09
used_cpu_sys_children:0.00
used_cpu_user_children:0.00

# Cluster
cluster_enabled:0

# Keyspace
db0:keys=136,expires=0,avg_ttl=0
127.0.0.1:6379>
```

### 1.12.24 LASTSAVE
`LASTSAVE`
> 返回最近一次 Redis 成功将数据保存到磁盘上的时间，以 UNIX 时间戳格式表示
```redis
127.0.0.1:6379> LASTSAVE
(integer) 1605247496
```
### 1.12.25 MONITOR
`MONITOR `
> 实时打印出 Redis 服务器接收到的命令，调试用
```redis
127.0.0.1:6379> MONITOR
OK
1605248107.645490 [0 127.0.0.1:20020] "COMMAND"
1605248110.056490 [0 127.0.0.1:20020] "info"
1605248118.239490 [0 127.0.0.1:20020] "get" "a"
```
### 1.12.26 ROLE
> 返回主从实例所属的角色
> 第一个参数是 master, slave, sentinel 三个中的一个。
```redis
127.0.0.1:6379> ROLE
1) "master"
2) (integer) 0
3) (empty list or set)
```
### 1.12.27 SAVE
> 同步保存数据到硬盘
> 执行一个同步保存操作，将当前 Redis 实例的所有数据快照(snapshot)以 RDB 文件的形式保存到硬盘
### 1.12.28 SHUTDOWN [NOSAVE] [SAVE]
`SHUTDOWN [NOSAVE] [SAVE] `
> 异步保存数据到硬盘，并关闭服务器
>  Shutdown 命令执行以下操作：
- 停止所有客户端
- 如果有至少一个保存点在等待，执行 SAVE 命令
- 如果 AOF 选项被打开，更新 AOF 文件
- 关闭 redis 服务器(server)
```redis
127.0.0.1:6379> SHUTDOWN
not connected>
```
### 1.12.29 SLAVEOF host port
`SLAVEOF host port`
> 将当前服务器转变为指定服务器的从属服务器(slave server)
> Slaveof 命令可以将当前服务器转变为指定服务器的从属服务器(slave server)。
> 如果当前服务器已经是某个主服务器(master server)的从属服务器，那么执行 `SLAVEOF host port` 将使当前服务器停止对旧主服务器的同步，丢弃旧数据集，转而开始对新主服务器进行同步。
> 另外，对一个从属服务器执行命令 `SLAVEOF NO ONE` 将使得这个从属服务器关闭复制功能，并从从属服务器转变回主服务器，原来同步所得的数据集不会被丢弃。
> 利用『 SLAVEOF NO ONE 不会丢弃同步所得数据集』这个特性，可以在主服务器失败的时候，将从属服务器用作新的主服务器，从而实现无间断运行。
```redis
redis 127.0.0.1:6379> SLAVEOF 127.0.0.1 6379
OK
redis 127.0.0.1:6379> SLAVEOF NO ONE
OK
```
### 1.12.30 SLOWLOG subcommand [argument]
`SLOWLOG subcommand [argument]`
> 管理 redis 的慢日志
> slowlog 是 Redis 用来记录查询执行时间的日志系统。
> 查询执行时间指的是不包括像客户端响应(talking)、发送回复等 IO 操作，而单单是执行一个查询命令所耗费的时间。
> 另外，slow log 保存在内存里面，读写速度非常快，因此你可以放心地使用它，不必担心因为开启 slow log 而损害 Redis 的速度。
`SLOWLOG LEN`
`SLOWLOG GET 2`
`SLOWLOG RESET`
### 1.12.31 SYNC
> 用于同步主从服务器
> 用于复制功能(replication)的内部命令
```redis
127.0.0.1:6379> SYNC
Entering slave output mode...  (press Ctrl-C to quit)
SYNC with master, discarding 13892 bytes of bulk transfer...
SYNC done. Logging commands from master.
"PING"
```
### 1.12.32 TIME
> 用于返回当前服务器时间。
> 包含两个字符串的列表： 第一个字符串是当前时间(以 UNIX 时间戳格式表示)，而第二个字符串是当前这一秒钟已经逝去的微秒数。
```redis
127.0.0.1:6379> TIME
1) "1605248754"
2) "877390"
127.0.0.1:6379> TIME
1) "1605248757"
2) "598662"
```
## 1.13 Redis GEO


> GEO 主要用于存储地理位置信息，并对存储的信息进行操作
- geoadd：添加地理位置的坐标。
- geopos：获取地理位置的坐标。
- geodist：计算两个位置之间的距离。
- georadius：根据用户给定的经纬度坐标来获取指定范围内的地理位置集合。
- georadiusbymember：根据储存在位置集合里面的某个地点获取指定范围内的地理位置集合。
- geohash：返回一个或多个位置对象的 geohash 值。
### 1.13.1 geoadd
`GEOADD key longitude latitude member [longitude latitude member ...]`
> 用于存储指定的地理空间位置，可以将一个或多个经度(longitude)、纬度(latitude)、位置名称(member)添加到指定的 key 中。
```redis
redis> GEOADD Sicily 13.361389 38.115556 "Palermo" 15.087269 37.502669 "Catania"
(integer) 2
redis> GEODIST Sicily Palermo Catania
"166274.1516"
redis> GEORADIUS Sicily 15 37 100 km
1) "Catania"
redis> GEORADIUS Sicily 15 37 200 km
1) "Palermo"
2) "Catania"
```
### 1.13.2 geopos
`GEOPOS key member [member ...]`
> 用于从给定的 key 里返回所有指定名称(member)的位置（经度和纬度），不存在的返回 nil。
```redis
redis> GEOADD Sicily 13.361389 38.115556 "Palermo" 15.087269 37.502669 "Catania"
(integer) 2
redis> GEOPOS Sicily Palermo Catania NonExisting
1) 1) "13.36138933897018433"
   2) "38.11555639549629859"
2) 1) "15.08726745843887329"
   2) "37.50266842333162032"
3) (nil)
```
### 1.13.3 geodist
`GEODIST key member1 member2 [m|km|ft|mi]`
> geodist 用于返回两个给定位置之间的距离。
> member1 member2 为两个地理位置。
> 最后一个距离单位参数说明：
- m ：米，默认单位。
- km ：千米。
- mi ：英里。
- ft ：英尺。
```redis
redis> GEOADD Sicily 13.361389 38.115556 "Palermo" 15.087269 37.502669 "Catania"
(integer) 2
redis> GEODIST Sicily Palermo Catania
"166274.1516"
redis> GEODIST Sicily Palermo Catania km
"166.2742"
redis> GEODIST Sicily Palermo Catania mi
"103.3182"
redis> GEODIST Sicily Foo Bar
(nil)
```
### 1.13.4 georadius、georadiusbymember
```
GEORADIUS key longitude latitude radius m|km|ft|mi [WITHCOORD] [WITHDIST] [WITHHASH] [COUNT count] [ASC|DESC] [STORE key] [STOREDIST key]
GEORADIUSBYMEMBER key member radius m|km|ft|mi [WITHCOORD] [WITHDIST] [WITHHASH] [COUNT count] [ASC|DESC] [STORE key] [STOREDIST key]
```
>georadius 以给定的经纬度为中心， 返回键包含的位置元素当中， 与中心的距离不超过给定最大距离的所有位置元素。
> georadiusbymember 和 GEORADIUS 命令一样， 都可以找出位于指定范围内的元素， 但是 georadiusbymember 的中心点是由给定的位置元素决定的， 而不是使用经度和纬度来决定中心点。
- m ：米，默认单位。
- km ：千米。
- mi ：英里。
- ft ：英尺。
- WITHDIST: 在返回位置元素的同时， 将位置元素与中心之间的距离也一并返回。
- WITHCOORD: 将位置元素的经度和维度也一并返回。
- WITHHASH: 以 52 位有符号整数的形式， 返回位置元素经过原始 geohash 编码的有序集合分值。 这个选项主要用于底层应用或者调试， 实际中的作用并不大。
- COUNT 限定返回的记录数。
- ASC: 查找结果根据距离从近到远排序。
- DESC: 查找结果根据从远到近排序。
```redis
redis> GEOADD Sicily 13.361389 38.115556 "Palermo" 15.087269 37.502669 "Catania"
(integer) 2
redis> GEORADIUS Sicily 15 37 200 km WITHDIST
1) 1) "Palermo"
   2) "190.4424"
2) 1) "Catania"
   2) "56.4413"
redis> GEORADIUS Sicily 15 37 200 km WITHCOORD
1) 1) "Palermo"
   2) 1) "13.36138933897018433"
      2) "38.11555639549629859"
2) 1) "Catania"
   2) 1) "15.08726745843887329"
      2) "37.50266842333162032"
redis> GEORADIUS Sicily 15 37 200 km WITHDIST WITHCOORD
1) 1) "Palermo"
   2) "190.4424"
   3) 1) "13.36138933897018433"
      2) "38.11555639549629859"
2) 1) "Catania"
   2) "56.4413"
   3) 1) "15.08726745843887329"
      2) "37.50266842333162032"
```

```redis
redis> GEOADD Sicily 13.583333 37.316667 "Agrigento"
(integer) 1
redis> GEOADD Sicily 13.361389 38.115556 "Palermo" 15.087269 37.502669 "Catania"
(integer) 2
redis> GEORADIUSBYMEMBER Sicily Agrigento 100 km
1) "Agrigento"
2) "Palermo"
```

### 1.13.5 geohash
> GEO 使用 geohash 来保存地理位置的坐标。
> geohash 用于获取一个或多个位置元素的 geohash 值。
```redis
redis> GEOADD Sicily 13.361389 38.115556 "Palermo" 15.087269 37.502669 "Catania"
(integer) 2
redis> GEOHASH Sicily Palermo Catania
1) "sqc8b49rny0"
2) "sqdtr74hyu0"
```

## 1.14 Redis Stream


> Stream 主要用于消息队列（MQ，Message Queue），Redis 本身是有一个 Redis 发布订阅 (pub/sub) 来实现消息队列的功能，但它有个缺点就是消息无法持久化，如果出现网络断开、Redis 宕机等，消息就会被丢弃。
> 简单来说发布订阅 (pub/sub) 可以分发消息，但无法记录历史消息。
> 而 Redis Stream 提供了消息的持久化和主备复制功能，可以让任何客户端访问任何时刻的数据，并且能记住每一个客户端的访问位置，还能保证消息不丢失。

> 它有一个消息链表，将所有加入的消息都串起来，每个消息都有一个唯一的 ID 和对应的内容：

> 每个 Stream 都有唯一的名称，它就是 Redis 的 key，在我们首次使用 xadd 指令追加消息时自动创建。

- Consumer Group ：消费组，使用 XGROUP CREATE 命令创建，一个消费组有多个消费者(Consumer)。
- last_delivered_id ：游标，每个消费组会有个游标 last_delivered_id，任意一个消费者读取了消息都会使游标 last_delivered_id 往前移动。
- pending_ids ：消费者(Consumer)的状态变量，作用是维护消费者的未确认的 id。 pending_ids 记录了当前已经被客户端读取的消息，但是还没有 ack (Acknowledge character：确认字符）。

### 1.14.1 消息队列相关命令：

#### 1.14.1.1 XADD - 添加消息到末尾
> 使用 XADD 向队列添加消息，如果指定的队列不存在，则创建一个队列，XADD 语法格式：
`XADD key ID field value [field value ...]`

- key ：队列名称，如果不存在就创建
-ID ：消息 id，我们使用 * 表示由 redis 生成，可以自定义，但是要自己保证递增性。
- field value ： 记录。

### 1.14.1.2 XTRIM - 对流进行修剪，限制长度
`XTRIM key MAXLEN [~] count`

- key ：队列名称
- MAXLEN ：长度
- count ：数量
```redis

```
### 1.14.1.3 XDEL - 删除消息
`XDEL key ID [ID ...]`

- key：队列名称
- ID ：消息 ID
```redis

```
### 1.14.1.4 XLEN - 获取流包含的元素数量，即消息长度
`XLEN key`

```redis

```
### 1.14.1.5 XRANGE - 获取消息列表，会自动过滤已经删除的消息
`XRANGE key start end [COUNT count]`

- key ：队列名
- start ：开始值， - 表示最小值
- end ：结束值， + 表示最大值
- count ：数量
```redis

```
### 1.14.1.6 XREVRANGE - 反向获取消息列表，ID 从大到小
`XREVRANGE key end start [COUNT count]`

- key ：队列名
- end ：结束值， + 表示最大值
- start ：开始值， - 表示最小值
- count ：数量
```redis

```
### 1.14.1.7 XREAD - 以阻塞或非阻塞方式获取消息列表
`XREAD [COUNT count] [BLOCK milliseconds] STREAMS key [key ...] id [id ...]`

- count ：数量
- milliseconds ：可选，阻塞毫秒数，没有设置就是非阻塞模式
- key ：队列名
- id ：消息 ID

```redis

```
### 1.14.2 消费者组相关命令：
#### 1.14.2.1 XGROUP CREATE - 创建消费者组
`XGROUP [CREATE key groupname id-or-$] [SETID key groupname id-or-$] [DESTROY key groupname] [DELCONSUMER key groupname consumername]`

- key ：队列名称，如果不存在就创建
- groupname ：组名。
- $ ： 表示从尾部开始消费，只接受新消息，当前 Stream 消息会全部忽略。

- 从头开始消费:
`XGROUP CREATE mystream consumer-group-name 0-0`
- 从尾部开始消费:
`XGROUP CREATE mystream consumer-group-name $`

#### 1.14.2.2 XREADGROUP GROUP - 读取消费者组中的消息
`XREADGROUP GROUP group consumer [COUNT count] [BLOCK milliseconds] [NOACK] STREAMS key [key ...] ID [ID ...]`

- group ：消费组名
- consumer ：消费者名。
- count ： 读取数量。
- milliseconds ： 阻塞毫秒数。
- key ： 队列名。
- ID ： 消息 ID。

#### 1.14.2.3 XACK - 将消息标记为"已处理"
#### 1.14.2.4 XGROUP SETID - 为消费者组设置新的最后递送消息ID
#### 1.14.2.5 XGROUP DELCONSUMER - 删除消费者
#### 1.14.2.6 XGROUP DESTROY - 删除消费者组
#### 1.14.2.7 XPENDING - 显示待处理消息的相关信息
#### 1.14.2.8 XCLAIM - 转移消息的归属权
#### 1.14.2.9 XINFO - 查看流和消费者组的相关信息；
#### 1.14.2.10 XINFO GROUPS - 打印消费者组的信息；
#### 1.14.2.11 XINFO STREAM - 打印流信息

# 2. 其他
## 2.1 Redis 数据备份与恢复


### 2.1.1 备份
> `SAVE` 命令用于创建当前数据库的备份。
> 创建`dump.rdb`文件；
> `BGSAVE` 在后台执行备份文件；
### 2.1.2 恢复
> 只需将备份文件 (dump.rdb) 移动到 redis 安装目录并启动服务即可。获取 redis 目录可以使用 CONFIG 命令，
```redis
127.0.0.1:6379> CONFIG get dir
1) "dir"
2) "C:\\SunGards\\ks_new\\src\\trade\\tools\\Redis_\xb0\xb2\xd7\xb0\xb0\xfc\xba\xcd\xbb\xf9\xb4\xa1\xce\xc4\xb5\xb5\\redis\xd6\xb1\xbd\xd3\xd4\xcb\xd0\xd0\xb0\xfc"
```
## 2.2 Redis 安全


> 可以通过 redis 的配置文件设置密码参数，这样客户端连接到 redis 服务就需要密码验证，这样可以让你的 redis 服务更安全。
### 2.2.1 密码验证查看
> 通过以下命令查看是否设置了密码验证：
```redis
127.0.0.1:6379> CONFIG get requirepass
1) "requirepass"
2) ""
```
> 默认情况下 requirepass 参数是空的，这就意味着你无需通过密码验证就可以连接到 redis 服务。
### 2.2.2 密码设置
> 可以通过`SET requirepass`命令来修改该参数：
```redis
127.0.0.1:6379> CONFIG set requirepass "runoob"
OK
127.0.0.1:6379> CONFIG get requirepass
1) "requirepass"
2) "runoob"
```
### 2.2.3 认证
`AUTH password`

```redis
127.0.0.1:6379> CONFIG get requirepass
1) "requirepass"
2) ""
127.0.0.1:6379> CONFIG set requirepass "abc123"
OK
127.0.0.1:6379> CONFIG get requirepass
(error) NOAUTH Authentication required.
127.0.0.1:6379> AUTH "abc123"
OK
127.0.0.1:6379> CONFIG GET requirepass
1) "requirepass"
2) "abc123"
```
## 2.3 Redis 性能测试


> 是通过同时执行多个命令实现的。
`redis-benchmark [option] [option value]`

```redis
# 同时执行 10000 个请求来检测性能：
> redis-benchmark -n 10000  -q
PING_INLINE: 10080.65 requests per second
PING_BULK: 9017.13 requests per second
SET: 9891.20 requests per second
GET: 9615.38 requests per second
INCR: 5540.17 requests per second
LPUSH: 7012.62 requests per second
RPUSH: 9891.20 requests per second
LPOP: 9708.74 requests per second
RPOP: 8291.87 requests per second
SADD: 9775.17 requests per second
SPOP: 8802.82 requests per second
LPUSH (needed to benchmark LRANGE): 10141.99 requests per second
LRANGE_100 (first 100 elements): 9727.63 requests per second
LRANGE_300 (first 300 elements): 10020.04 requests per second
LRANGE_500 (first 450 elements): 9930.49 requests per second
LRANGE_600 (first 600 elements): 9425.07 requests per second
MSET (10 keys): 9149.13 requests per second
```

|   No   | 选项  |                    描述                     |   默认值   |
| ------ | ----- | ------------------------------------------ | --------- |
| 1	     | -h	 | 指定服务器主机名	                             | 127.0.0.1 |
| 2	     | -p	 | 指定服务器端口	                             | 6379      |
| 3	     | -s	 | 指定服务器 socket	                         |           |
| 4	     | -c	 | 指定并发连接数                               | 	50      |
| 5	     | -n	 | 指定请求数	                                 | 10000     |
| 6	     | -d	 | 以字节的形式指定 SET/GET 值的数据大小	         | 2         |
| 7	     | -k	 | 1=keep alive 0=reconnect	                 | 1         |
| 8	     | -r	 | SET/GET/INCR 使用随机 key, SADD 使用随机值	 |           |
| 9	     | -P	 | 通过管道传输 \<numreq\> 请求	                 | 1         |
| 10	 | -q	 | 强制退出 redis。仅显示 query/sec 值| |
| 11	 | --csv | 	以 CSV 格式输出	                           |           |
| 12	 | -l	 | 生成循环，永久执行测试	                     |           |
| 13	 | -t	 | 仅运行以逗号分隔的测试命令列表。	             |           |
| 14	 | -I	 | Idle 模式。仅打开 N 个 idle 连接并等待。	     |           |

```redis
$ redis-benchmark -h 127.0.0.1 -p 6379 -t set,lpush -n 10000 -q
SET: 146198.83 requests per second
LPUSH: 145560.41 requests per second
```
> 以上实例中主机为 127.0.0.1，端口号为 6379，执行的命令为 set,lpush，请求数为 10000，通过 -q 参数让结果只显示每秒执行的请求数。
## 2.4 Redis 客户端连接


### 2.4.1  连接
> 通过监听一个 TCP 端口或者 Unix socket 的方式来接收来自客户端的连接，当一个连接建立后，Redis 内部会进行以下一些操作：
> 首先，客户端 socket 会被设置为非阻塞模式，因为 Redis 在网络事件处理上采用的是非阻塞多路复用模型。
> 然后为这个 socket 设置 TCP_NODELAY 属性，禁用 Nagle 算法
> 然后创建一个可读的文件事件用于监听这个客户端 socket 的数据发送

最大连接数
在 Redis2.4 中，最大连接数是被直接硬编码在代码里面的，而在2.6版本中这个值变成可配置的。

maxclients 的默认值是 10000，你也可以在 redis.conf 中对这个值进行修改。

### 2.4.2 最大连接
```redis
config get maxclients
1) "maxclients"
2) "10000"
```
## 2.5 Redis 管道技术


> Redis是一种基于客户端-服务端模型以及请求/响应协议的TCP服务。这意味着通常情况下一个请求会遵循以下步骤：
> 客户端向服务端发送一个查询请求，并监听Socket返回，通常是以阻塞模式，等待服务端响应。
> 服务端处理命令，并将结果返回给客户端。

### 2.5.1 管道
> Redis 管道技术可以在服务端未响应时，客户端可以继续向服务端发送请求，并最终一次性读取所有服务端的响应。
## 2.6 Redis 分区



# 3.redis src

[redis-5.0.0.tar.gz](http://download.redis.io/releases/redis-5.0.0.tar.gz)
## 3.1 SDS简单动态字符串Simple Dynamic Strings


### 3.1.0 数据结构
#### 3.1.0.1 如何实现一个扩容方便且二进制安全的字符串呢？
> 什么是二进制安全？通俗地讲，C语言中，用“\0”表示字符串的结束，如果字符串中本身就有“\0”字符，字符串就会被截断，即非二进制安全；若通过某种机制，保证读写字符串时不损害其内容，则是二进制安全。

#### 3.1.0.2 字符串设计
>首先需要一个字符串指针；
>为了方便上层的接口调用，该结构还需要记录一些统计信息，如当前数据长度和剩余容量等，
>例如：
```c
struct sds {
    int len;// buf 中已占用字节数
    int free;// buf 中剩余可用字节数
    char buf[];// 数据空间
};
```
[ len | free |   buf               ]
[  4   |   4   |   buf               ]
> 字段len和字段free各占4个字节，紧接着存放字符串。

#### 3.1.0.3 优点
1. 有单独的统计变量len和free（称为头部）。可以很方便地得到字符串长度。
2. 内容存放在柔性数组buf中，SDS对上层暴露的指针不是指向结构体SDS的指针，而是直接指向柔性数组buf的指针。上层可像读取C字符串一样读取SDS的内容，兼容C语言处理字符串的各种函数。
3. 由于有长度统计变量len的存在，读写字符串时不依赖“\0”终止符，保证了二进制安全。

> buf[]是一个柔性数组。柔性数组成员（flexible array member），也叫伸缩性数组成员，只能被放在结构体的末尾。包含柔性数组成员的结构体，通过malloc函数为柔性数组动态分配内存。
柔性数组的地址和结构体是连续的，这样查找内存更快(因为不需要额外通过指针找到字符串的位置)
可以很方便地通过柔性数组的首地址偏移得到结构体首地址，进而能很方便地获取其余变量。

#### 3.1.0.4 考虑改进空间
> 不同长度的字符串是否有必要占用相同大小的头部？一个int占4字节，在实际应用中，存放于Redis中的字符串往往没有这么长，每个字符串都用4字节存储未免太浪费空间了。

##### 3.1.0.4.1 方法，区分类型，位存储长度
1. 区分不同长度类型
我们考虑增加一个字段flags来标识类型，用最小的1字节来存储，且把flags加在柔性数组buf之前，这样虽然多了1字节，但通过偏移柔性数组的指针即能快速定位flags，区分类型，也可以接受；
2. 短字符串用位存储长度
5种类型（长度1字节、2字节、4字节、8字节、小于1字节）的SDS至少要用3位来存储类型（2^3 ＝8），1个字节8位，剩余的5位存储长度，可以满足长度小于32的短字符串。

#####  3.1.0.4.2 sdshr5 存储小于32位的短字符串
```c
struct __attribute__ ((__packed__))sdshdr5 {
    unsigned char flags; /* 低3位存储类型, 高5位存储长度 */
    char buf[];          /* 柔性数组，存放实际内容 */
};
```
flags占1个字节，其低3位（bit）表示type，高5位（bit）表示长度
能表示的长度区间为0～31（2^5 -1），flags后面就是字符串的内容。
```
            sdshr5 struct
[  1 bytes | bytes | bytes | ... | bytes ]
[   flags  |         buf                 ]
     |
[   flags  ]__________________________________________
|                                                      \
[ 1bit | 1bit | 1bit | 1bit | 1bit | 1bit | 1bit | 1bit ]
[        type        |                len               ]
```
##### 3.1.0.4.3 大于31字符串，存len和free
```
            sdshr16 struct
[ 2 bytes | 2 bytes |   1 bytes | bytes | ... | bytes ]
[   len   |  alloc  |   flags   |         buf         ]
                         |
   _________________[   flags   ]___________________
/                                                      \
[ 1bit | 1bit | 1bit | 1bit | 1bit | 1bit | 1bit | 1bit ]
[        type        |              unused              ]
```
flags 占1个字节，其中3位存储类型，但剩余5位不存储长度。
前"表头"部总共占用 `(len + alloc + flags) 2+2+1 = 5` bytes,

##### 3.1.0.4.4 不同字符串类型
1. redis中字符串类型宏定义,3位存储，2^3 -1 =7
```c
#define SDS_TYPE_5  0
#define SDS_TYPE_8  1
#define SDS_TYPE_16 2
#define SDS_TYPE_32 3
#define SDS_TYPE_64 4
```
2. 不同类型数据结构
这4种结构的成员变量类似，唯一的区别是len和alloc的类型不同。
- 1 len ：表示buf中已占用字节数。
- 2 alloc ：表示buf中已分配字节数，不同于free，记录的是为buf分配的总长度。
- 3 flags ：标识当前结构体的类型，低3位用作标识位，高5位预留。
- 4 buf ：柔性数组，真正存储字符串的数据空间。
>  结构最后的buf依然是柔性数组，通过对数组指针作“减一”操作，能方便地定位到flags。
```c
struct __attribute__((__packed__))sdshdr8 {
    uint8_t len; /* 已使用长度，用1字节存储 */
    uint8_t alloc; /* 总长度，用1字节存储*/
    unsigned char flags; /* 低3位存储类型, 高5位预留 */
    char buf[];/*柔性数组，存放实际内容*/
};
struct __attribute__((__packed__))sdshdr16 {
    uint16_t len; /*已使用长度，用2字节存储*/
    uint16_t alloc; /* 总长度，用2字节存储*/
    unsigned char flags; /* 低3位存储类型, 高5位预留 */
    char buf[];/*柔性数组，存放实际内容*/
};
struct __attribute__((__packed__))sdshdr32 {
    uint32_t len; /*已使用长度，用4字节存储*/
    uint32_t alloc; /* 总长度，用4字节存储*/
    unsigned char flags;/* 低3位存储类型, 高5位预留 */
    char buf[];/*柔性数组，存放实际内容*/
};
struct __attribute__((__packed__))sdshdr64 {
    uint64_t len; /*已使用长度，用8字节存储*/
    uint64_t alloc; /* 总长度，用8字节存储*/
    unsigned char flags; /* 低3位存储类型, 高5位预留 */
    char buf[];/*柔性数组，存放实际内容*/
};
```
##### 3.1.0.4.5 对齐指定
`__attribute__((__packed__))`需要重点关注。
一般情况下，结构体会按其所有变量大小的最小公倍数做字节对齐，而用packed修饰后，结构体则变为按1字节对齐。
以sdshdr32为例，
修饰前按4字节对齐大小为12(4×3)字节；
>（4+4 + 1+3）这里的3是为了对齐前面的4；
修饰后按1字节对齐，注意buf是个char类型的柔性数组，地址连续，始终在flags之后。
> (4+4+ 1)这里是9；
无`__packed__` 修饰：
```
|    1  |    2   |   3   |   4   |
|              len               |  4
|              alloc             |  4
| flags |    X       X       X   |  4
|           ... buf ...          |  buf
```
有`__packed__` 修饰：
```
|    1  |    2   |   3   |   4   |
|              len               |  4
|              alloc             |  4
| flags |       buf ...          |  1, buf
|           ... buf ...          |  ...buf
```
好处
1. 节省内存 （12 -9 =3）字节
2. 返回SDS是buf指针，按1字节对齐，无论何种类型，都能通过`通过(char*)sh+hdrlen`得到buf指针地址（其中hdrlen是结构体长度，通过sizeof计算得到）.都能通过buf[-1]找到flags，因为此时按1字节对齐。

### 3.1.1 创建字符串
> Redis通过sdsnewlen函数创建SDS
> 根据字符串长度选择合适的类型
> 初始化完相应的统计值后
> 返回指向字符串内容的指针
```c
sds sdsnewlen(const void *init, size_t initlen) {
    void *sh;
    sds s;
    char type = sdsReqType(initlen);//根据字符串长度选择不同的类型
    if (type == SDS_TYPE_5 && initlen == 0) type = SDS_TYPE_8;//SDS_TYPE_5强制转化为SDS_TYPE_8
    int hdrlen = sdsHdrSize(type);//计算不同头部所需的长度
    unsigned char *fp; /* 指向flags的指针 */
    sh = s_malloc(hdrlen+initlen+1);//"+1"是为了结束符'\0'
    ...
    s = (char*)sh+hdrlen;//s是指向buf的指针
    fp = ((unsigned char*)s)-1;//s是柔性数组buf的指针,-1即指向flags
    ...
    s[initlen] = '\0';//添加末尾的结束符
    return s;
}
```
> 且对于sdshdr5类型，在创建空字符串时会强制转换为sdshdr8。原因可能是创建空字符串后，其内容可能会频繁更新而引发扩容，故创建时直接创建为sdshdr8。

** 创建SDS的大致流程：**
首先计算好不同类型的头部和初始长度，然后动态分配内存。

1. 创建空字符串时，SDS_TYPE_5被强制转换为SDS_TYPE_8。
2. 长度计算时有“+1”操作，是为了算上结束符“\0”。
3. 返回值是指向sds结构buf字段的指针。

返回值sds的类型定义如下：
`typedef char *sds;`

### 3.1.2 释放字符串
#### 3.1.2.1 sdsfree
> SDS提供了直接释放内存的方法—sdsfree
> 通过对s的偏移，可定位到SDS结构体的首部，然后调用s_free释放内存：

```c
void sdsfree(sds s) {
    if (s == NULL) return;
    s_free((char*)s-sdsHdrSize(s[-1]));//此处直接释放内存
}
```

`#define s_free zfree`
#### 3.1.2.2 sdsclear
> 为了优化性能（减少申请内存的开销），SDS提供了不直接释放内存，而是通过重置统计值达到清空目的的方法——sdsclear。该方法仅将SDS的len归零，此处已存在的buf并没有真正被清除，新的数据可以覆盖写，而不用重新申请内存。
```c
void sdsclear(sds s) {
    sdssetlen(s, 0); //统计值len归零
    s[0] = '\0';//清空buf
}
```

```c
static inline void sdssetlen(sds s, size_t newlen) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
    //...
        case SDS_TYPE_8:
            SDS_HDR(8,s)->len = newlen;
            break;
    //...
    }
}
```

### 3.1.3 拼接字符串
#### 3.1.3.1 sdscatsds实现
```c
sds sdscatsds(sds s, const sds t) {
    return sdscatlen(s, t, sdslen(t));
}
```
> sdscatsds是暴露给上层的方法，其最终调用的是sdscatlen。
> 可能涉及SDS的扩容，sdscatlen中调用sdsMakeRoomFor对带拼接的字符串s容量做检查，若无须扩容则直接返回s；若需要扩容，则返回扩容好的新字符串s。
> 函数中的len、curlen等长度值是不含结束符的，而拼接时用memcpy将两个字符串拼接在一起，指定了相关长度，故该过程保证了二进制安全。最后需要加上结束符。

```c
/* 将指针t的内容和指针s的内容拼接在一起，该操作是二进制安全的*/
sds sdscatlen(sds s, const void *t, size_t len) {
    size_t curlen = sdslen(s);

    s = sdsMakeRoomFor(s,len);
    if (s == NULL) return NULL;
    memcpy(s+curlen, t, len);//直接拼接，保证了二进制安全
    sdssetlen(s, curlen+len);
    s[curlen+len] = '\0';//加上结束符
    return s;
}
```

#### 3.1.3.2 sdsMakeRoomFor
> 有如下扩容策略：

##### 3.1.3.2.1 若avail >=addlen,无需扩容
```c
sds sdsMakeRoomFor(sds s, size_t addlen)
{
    void *sh, *newsh;
    size_t avail = sdsavail(s);
    size_t len, newlen;
    char type, oldtype = s[-1] & SDS_TYPE_MASK;//s[-1]即flags
    int hdrlen;
    if (avail >= addlen) return s;//无须扩容，直接返回
    ...
}
```

##### 3.1.3.2.2 若avail <addlen, 分情况
1. 新增后总长度len+addlen<1MB的，按新长度的2倍扩容；
2. 新增后总长度len+addlen>1MB的，按新长度加上1MB扩容

```c
sds sdsMakeRoomFor(sds s, size_t addlen)
{
    ...
    newlen = (len+addlen);
    if (newlen < SDS_MAX_PREALLOC)// SDS_MAX_PREALLOC这个宏的值是1MB
        newlen *= 2;
    else
        newlen += SDS_MAX_PREALLOC;
    ...
}
```

`#define SDS_MAX_PREALLOC (1024*1024)`

##### 3.1.3.2.3 选取类型，分配空间
> 最后根据新长度重新选取存储类型，并分配空间。此处若无须更改类型，通过realloc扩大柔性数组即可；否则需要重新开辟内存，并将原字符串的buf内容移动到新位置。
```c
sds sdsMakeRoomFor(sds s, size_t addlen)
{
    ...
    type = sdsReqType(newlen);
    /* type5的结构不支持扩容，所以这里需要强制转成type8*/
    if (type == SDS_TYPE_5) type = SDS_TYPE_8;
    hdrlen = sdsHdrSize(type);
    if (oldtype==type) {
    /*无须更改类型，通过realloc扩大柔性数组即可，注意这里指向buf的指针s被更新了*/
        newsh = s_realloc(sh, hdrlen+newlen+1);
        if (newsh == NULL) return NULL;
        s = (char*)newsh+hdrlen;
    } else {
        /*扩容后数据类型和头部长度发生了变化，此时不再进行realloc操作，而是直接重新开辟内存，拼接完内容后，释放旧指针*/
        newsh = s_malloc(hdrlen+newlen+1);//按新长度重新开辟内存
        if (newsh == NULL) return NULL;
        memcpy((char*)newsh+hdrlen, s, len+1);//将原buf内容移动到新位置
        s_free(sh);//释放旧指针
        s = (char*)newsh+hdrlen;//偏移sds结构的起始地址，得到字符串起始地址
        s[-1] = type;//为falgs赋值
        sdssetlen(s, len);//为len属性赋值
    }
    sdssetalloc(s, newlen);//为alloc属性赋值
    return s;
}
```

### 3.1.3 其他API
|       函数名        |                        说明                         |
| ------------------ | -------------------------------------------------- |
| sdsempty           | 创建一个空字符串，长度为0,内容为n                     |
| sdsnew             | 根据给定的C字符串创建SDS                             |
| sdsdup             | 复制给定的SDS                                       |
| sdsupdatelen       | 手动刷新SDS的相关统计值                              |
| sdsRemoveFreeSpace | 与sdsMakeRoomFor相 反 ， 对 空 闲 过 多 的SDS做 缩 容 |
| sdsAllocSize | 返回给定SDS当前占用的内存大小 |
| sdsgrow zero |将SDS扩容到指定长度，井用0填充新增内容|
|sdscpylcn |将C字符串复制到给定SDS中 |
|sdstrim |从SDS两端清除所有给定的字符 |
|sdscmp |比较两给定SDS的实际大小 |
|sdssplitlen |按给定的分隔符对SDS进行切分 |

## 3.2 跳跃表


### 3.2.1 引入跳跃表
#### 3.2.1.0 有序链表
> 有序链表，所有元素以递增或递减方式有序排列的数据结构，其中每个节点都有指向下个节点的next指针，最后一个节点的next指针指向NULL。
`1->11->21->31->41->51->61->NULL`
> 如果要查询值为51的元素，需要从第一个元素开始依次向后查找、比较才可以找到，查找顺序为1→11→21→31→41→51，共6次比较，时间复杂度为O(N)。
> 有序链表的插入和删除操作都需要先找到合适的位置再修改next指针，修改操作基本不消耗时间，所以插入、删除、修改有序链表的耗时主要在查找元素上。
#### 3.2.1.1 分层 跳跃
将有序链表中的部分节点分层，每一层都是一个有序链表。
在查找时优先从最高层开始向后查找，当到达某节点时，如果next节点值**大于**要查找的值或next指针**指向NULL**，则从当前节点下降一层继续向后查找。
如果找到则返回节点；否则返回NULL。
在节点数量比较多时，可以跳过一些节点，查询效率大大提升，这就是跳跃表的基本思想。

```
第2层 1 ---->21----------------->NULL
第1层 1 ---->21----->41----->61->NULL
第0层 1->11->21->31->41->51->61->NULL
```
1. 从第2层开始，1节点比51节点小，向后比较。
2. 21节点比51节点小，继续向后比较。第2层21节点的next指针指向NULL，所以从21节点开始需要下降一层到第1层继续向后比较。
3. 第1层中，21节点的next节点为41节点，41节点比51节点小，继续向后比较。第1层41节点的next节点为61节点，比要查找的51节点大，所以从41节点开始下降一层到第0层继续向后比较。
4. 在第0层，51节点为要查询的节点，节点被找到。
> 总共查找4次就可以找到51节点，比有序链表少2次。当数据量大时，优势会更明显。
#### 3.2.1.2 跳跃表性质
1. 跳跃表由很多层构成。
2. 跳跃表有一个头（header）节点，头节点中有一个64层的结构，每层的结构包含指向本层的下个节点的指针，指向本层下个节点中间所跨越的节点个数为本层的跨度（span）。
3. 除头节点外，层数最多的节点的层高为跳跃表的高度（level），图3-3中跳跃表的高度为3。
4. 每层都是一个有序链表，数据递增。
5. 除header节点外，一个元素在上层有序链表中出现，则它一定会在下层有序链表中出现。
6. 跳跃表每层最后一个节点指向NULL，表示本层有序链表的结束。
7. 跳跃表拥有一个tail指针，指向跳跃表最后一个节点。
8. 最底层的有序链表包含所有节点，最底层的节点个数为跳跃表的长度（length）（不包括头节点），图3-3中跳跃表的长度为7。
9. 每个节点包含一个后退指针，头节点和第一个节点指向NULL；其他节点指向最底层的前一个节点。

```
                 +---------+
                 |L63      | ----> NULL
                 |---------|
                 |...      |
                 |---------|
                 |L4       | ----> NULL
                 |---------|
                 |L3       | ----> NULL
                 |---------|  1  +---------+         2           +---------+   4
                 |L2       | --> |L2       | ------------------> |L2       | ----> NULL
                 |---------|  1  |---------|         2           |---------|         2           +---------+         2           +---------+
                 |L1       | --> |L1       | ------------------> |L1       | ------------------> |L1       | ------------------> |L1       | --> NULL
+--------+       |---------|  1  |---------|  1  +---------+  1  |---------|  1  +---------+  1  |---------|  1  +---------+  1  |---------|
|header  |-+     |L0       | --> |L0       | --> |L0       | --> |L0       | --> |L0       | --> |L0       | --> |L0       | --> |L0       | --> NULL
|--------| |     |---------|     |---------|     |---------|     |---------|     |---------|     |---------|     |---------|     |---------|
|tail    | |  +--|backward |  +- |backward | <-- |backward | <-- |backward | <-- |backward | <-- |backward | <-- |backward | <-- |backward |
|--------| |  |  |---------|  |  |---------|     |---------|     |---------|     |---------|     |---------|     |---------|     |---------|
|length=7| |  |--|ele      |  |  |ele      |     |ele      |     |ele      |     |ele      |     |ele      |     |ele      |     |ele      |
|--------| |  |  |---------| NULL|---------|     |---------|     |---------|     |---------|     |---------|     |---------|     |---------|
|level=3 | | NULL|score=0  |     |score=1  |     |score=11 |     |score=21 |     |score=31 |     |score=41 |     |score=51 |     |score=61 |
+--------+ |     +---------+     +---------+     +---------+     +---------+     +---------+     +---------+     +---------+     +---------+
           |       ^
           |       |
           +-------+

```

跳跃表每个节点维护了多个指向其他节点的指针，所以在跳跃表进行查找、插入、删除操作时可以跳过一些节点，快速找到操作需要的节点。
归根结底，跳跃表是以牺牲空间的形式来达到快速查找的目的。跳跃表与平衡树相比，实现方式更简单，只要熟悉有序链表，就可以轻松地掌握跳跃表。

### 3.1.2 跳跃表节点与结构
#### 3.1.2.1 跳跃表节点
> 跳跃表节点的zskiplistNode结构体。

- server.h
```c server.h
typedef struct zskiplistNode {
    sds ele;
    double score;
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned int span;
    } level[];
} zskiplistNode;
```

1. ele：用于存储字符串类型的数据。
2. score：用于存储排序的分值。
3. backward：后退指针，只能指向当前节点最底层的前一个节点，头节点和第一个节点——backward指向NULL，从后向前遍历跳跃表时使用。
4. level：为柔性数组。每个节点的数组长度不一样，在生成跳跃表节点时，随机生成一个1～64的值，值越大出现的概率越低。
   level数组的每项包含以下两个元素。
  - forward：指向本层下一个节点，尾节点的forward指向NULL。
  - span：forward指向的节点与本节点之间的元素个数。span值越大，跳过的节点个数越多。

> 跳跃表是Redis有序集合的底层实现方式之一，所以每个节点的ele存储有序集合的成员member值，score存储成员score值。
> 所有节点的分值是按从小到大的方式排序的，当有序集合的成员分值相同时，节点会按member的字典序进行排序。

#### 3.1.2.2 跳跃表结构
> 除了跳跃表节点外，还需要一个跳跃表结构来管理节点，Redis使用zskiplist结构体，定义如下：
```c
typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;
```
该结构体包含如下属性。

1. header：指向跳跃表头节点。
    头节点是跳跃表的一个特殊节点，它的level数组元素个数为64。
    头节点在有序集合中不存储任何member和score值，ele值为NULL，score值为0；也不计入跳跃表的总长度。
    头节点在初始化时，64个元素的forward都指向NULL，span值都为0。
2. tail：指向跳跃表尾节点。
3. length：跳跃表长度，表示除头节点之外的节点总数。
4. level：跳跃表的高度。
通过跳跃表结构体的属性我们可以看到，程序可以在O(1)的时间复杂度下,快速获取到跳跃表的头节点、尾节点、长度和高度。

### 3.1.3 跳跃表操作
#### 3.1.3.1 创建跳跃表
##### 3.1.3.1.1 节点层高
节点层高的最小值为1，最大值是ZSKIPLIST_MAXLEVEL，Redis5中节点层高的值为64。
- server.h
`#define ZSKIPLIST_MAXLEVEL 64 /* Should be enough for 2^64 elements */`

Redis通过zslRandomLevel函数随机生成一个1～64的值，作为新建节点的高度，值越大出现的概率越低。
节点层高确定之后便不会再修改。生成随机层高的代码如下。

```c
// server.h
#define ZSKIPLIST_P 0.25      /* Skiplist P = 1/4 */

// t_zset.c
/* Returns a random level for the new skiplist node we are going to create.
 * The return value of this function is between 1 and ZSKIPLIST_MAXLEVEL
 * (both inclusive), with a powerlaw-alike distribution where higher
 * levels are less likely to be returned. */
int zslRandomLevel(void) {
    int level = 1;
    while ((random()&0xFFFF) < (ZSKIPLIST_P * 0xFFFF))
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}
```
level的初始值为1，通过while循环，每次生成一个随机值，取这个值的低16位作为x，当x小于0.25倍的0xFFFF时，level的值加1；
否则退出while循环。最终返回level和ZSKIPLIST_MAXLEVEL两者中的最小值。

下面计算节点的期望层高。假设p=ZSKIPLIST_P：

1. 节点层高为1的概率为(1-p)。
2. 节点层高为2的概率为p(1-p)。
3. 节点层高为3的概率为p^2 (1-p)。
4. ……
5. 节点层高为n的概率为p^(n-1) *  (1-p)。
所以节点的期望层高为
```
E=1*(1-p)+2*p(1-p) + 3*p^2*(1-p)+...
```
=(1-p)
$\sum_{i=1}^8$
$ip^i-1$
=1/(1-p)
当p＝0.25时，跳跃表节点的期望层高为1/(1-0.25)≈1.33。

##### 3.1.3.1.2 创建跳跃表节点
跳跃表的每个节点都是有序集合的一个元素，在创建跳跃表节点时，待创建节点的层高、分值、member等都已确定。
- t_zset.c

```c
/* Create a skiplist node with the specified number of levels.
 * The SDS string 'ele' is referenced by the node after the call. */
zskiplistNode *zslCreateNode(int level, double score, sds ele) {
    zskiplistNode *zn =
        zmalloc(sizeof(*zn)+level*sizeof(struct zskiplistLevel));
    zn->score = score;
    zn->ele = ele;
    return zn;
}
```

###### 3.1.3.1.2.1 申请节点内存
对于跳跃表的每个节点，我们需要申请内存来存储，代码如下。
```c
zskiplistNode *zn =
     zmalloc(sizeof(*zn)+level*sizeof(struct zskiplistLevel))
```
zskiplistNode结构体的最后一个元素为柔性数组，申请内存时需要指定柔性数组的大小，
一个节点占用的内存大小为zskiplistNode的内存大小与level个zskiplistLevel的内存大小之和。

###### 3.1.3.1.2.2 节点变量初始化
分配好空间之后，进行节点变量初始化。代码如下。
```
zn->score = score;
zn->ele = ele;
return zn;
```

##### 3.1.3.1.3 头节点
头节点是一个特殊的节点，不存储有序集合的member信息。
头节点是跳跃表中第一个插入的节点，其level数组的每项forward都为NULL，span值都为0。
```c
for (j = 0; j < ZSKIPLIST_MAXLEVEL; j++) {
     zsl->header->level[j].forward = NULL;
     zsl->header->level[j].span = 0;
}
```

##### 3.1.3.1.4 创建跳跃表的步骤
创建完头节点后，就可以创建跳跃表。创建跳跃表的步骤如下。

1. 创建跳跃表结构体对象zsl。
2. 将zsl的头节点指针指向新创建的头节点。
3. 跳跃表层高初始化为1，长度初始化为0，尾节点指向NULL。

相关代码如下。
```c
/* Create a new skiplist. */
zskiplist *zslCreate(void) {
    int j;
    zskiplist *zsl;

    zsl = zmalloc(sizeof(*zsl));
    zsl->level = 1;
    zsl->length = 0;
    zsl->header = zslCreateNode(ZSKIPLIST_MAXLEVEL,0,NULL);
    for (j = 0; j < ZSKIPLIST_MAXLEVEL; j++) {
        zsl->header->level[j].forward = NULL;
        zsl->header->level[j].span = 0;
    }
    zsl->header->backward = NULL;
    zsl->tail = NULL;
    return zsl;
}
```

#### 3.1.3.2 插入节点
> 插入节点的步骤：
①查找要插入的位置；
②调整跳跃表高度；
③插入节点；
④调整backward。

```c
/* Insert a new node in the skiplist. Assumes the element does not already
 * exist (up to the caller to enforce that). The skiplist takes ownership
 * of the passed SDS string 'ele'. */
zskiplistNode *zslInsert(zskiplist *zsl, double score, sds ele) {
    zskiplistNode *update[ZSKIPLIST_MAXLEVEL], *x;
    unsigned int rank[ZSKIPLIST_MAXLEVEL];
    int i, level;

    serverAssert(!isnan(score));
    x = zsl->header;
    for (i = zsl->level-1; i >= 0; i--) {
        /* store rank that is crossed to reach the insert position */
        rank[i] = i == (zsl->level-1) ? 0 : rank[i+1];
        while (x->level[i].forward &&
                (x->level[i].forward->score < score ||
                    (x->level[i].forward->score == score &&
                    sdscmp(x->level[i].forward->ele,ele) < 0)))
        {
            rank[i] += x->level[i].span;
            x = x->level[i].forward;
        }
        update[i] = x;
    }
    /* we assume the element is not already inside, since we allow duplicated
     * scores, reinserting the same element should never happen since the
     * caller of zslInsert() should test in the hash table if the element is
     * already inside or not. */
    level = zslRandomLevel();
    if (level > zsl->level) {
        for (i = zsl->level; i < level; i++) {
            rank[i] = 0;
            update[i] = zsl->header;
            update[i]->level[i].span = zsl->length;
        }
        zsl->level = level;
    }
    x = zslCreateNode(level,score,ele);
    for (i = 0; i < level; i++) {
        x->level[i].forward = update[i]->level[i].forward;
        update[i]->level[i].forward = x;

        /* update span covered by update[i] as x is inserted here */
        x->level[i].span = update[i]->level[i].span - (rank[0] - rank[i]);
        update[i]->level[i].span = (rank[0] - rank[i]) + 1;
    }

    /* increment span for untouched levels */
    for (i = level; i < zsl->level; i++) {
        update[i]->level[i].span++;
    }

    x->backward = (update[0] == zsl->header) ? NULL : update[0];
    if (x->level[0].forward)
        x->level[0].forward->backward = x;
    else
        zsl->tail = x;
    zsl->length++;
    return x;
}
```
##### 3.1.3.2.1 查找要插入的位置<a id="3.1.3.2.1"></a>
查找是跳跃表操作中使用最多的操作，无论是获取、插入还是删除，都需要查找到指定的节点位置。
通过3.1节内容，我们已经大概知道了跳跃表查找的基本逻辑，下面借助跳跃表的插入节点的过程深入了解跳跃表的查找过程。

```c
                 +---------+
                 |L63      | ----> NULL
                 |---------|
                 |...      |
                 |---------|
                 |L4       | ----> NULL
                 |---------|
                 |L3       | ----> NULL
                 |---------|
                 |L2       |
                 |---------|   1  +---------+   2
                 |L1       | ---> |L1       | ----> NULL
+--------+       |---------|   1  |---------|  1   +---------+  1   +---------+
|header  |-+     |L0       | ---> |L0       | ---> |L0       | ---> |L0       |  --> NULL
|--------| |     |---------|      |---------|      |---------|      |---------|
|tail    | |  +--|backward |   +- |backward | <--- |backward | <--- |backward |
|--------| |  |  |---------|   |  |---------|      |---------|      |---------|
|length=3| |  |--|ele      |   |  |ele      |      |ele      |      |ele      |
|--------| |  |  |---------|  NULL|---------|      |---------|      |---------|
|level=2 | | NULL|score=0  |      |score=1  |      |score=21 |      |score=41 |
+--------+ |     +---------+      +---------+      +---------+      +---------+
           |       ^
           |       |
           +-------+
```
如图3-4所示的跳跃表，长度为3，高度为2。若要插入一个节点，分值为31，层高为3，则插入节点时查找被更新节点的代码如下。
```c
x = zsl->header;
for (i = zsl->level-1; i >= 0; i--) {
    rank[i] = i == (zsl->level-1) ? 0 : rank[i+1];
    while (x->level[i].forward &&
            (x->level[i].forward->score < score ||
                (x->level[i].forward->score == score &&
                sdscmp(x->level[i].forward->ele,ele) < 0)))
    {
        rank[i] += x->level[i].span;
        x = x->level[i].forward;
    }
    update[i] = x;
}
```
为了找到要更新的节点，我们需要以下两个长度为64的数组来辅助操作。
- update[]：插入节点时，需要更新被插入节点每层的前一个节点。由于每层更新的节点不一样，所以将每层需要更新的节点记录在update[i]中。
- rank[]：记录当前层从header节点到update[i]节点所经历的步长，在更新update[i]的span和设置新插入节点的span时用到。

查找节点（score=31，level=3）的插入位置，逻辑如下。
```
x = zsl->header
i=zsl->level-1 ,i = 2-1, i=1;
  rank[1] =  (i == zsl->level-1): 0
  x->level[1].forward , header->level[1].forward 不为空，
    判断 x->level[1].forward->score 即1 小于 score (31),进入while，
      rank[1] += x->level[1].span ,即rank[1] = 0 + 1 【rank[1] = 1,】
      x = x->level[1].forward, x指向score为1的节点，
  x->level[1].forward 指向NULL，不进入while循环，此时
  【update[1] = x】 ,x为第一个节点；
  for 循环 ,i--,i=0
  rank[0] = (0 == 1?0: rank[1]) , rank[0]= rank[1] = 1
  while 循环，判断 x->level[0]->forward, x是第一个score为1的节点，x的level[0] 的 forward不为空，
    判断 x->level[0].forward->score = 21，小于 score (31),进入while
      rank[0] += x->level[0].span ,rank[0] = 1+1,【rank[0]=2】
      x=x->level[0].forward, x指向score为21的节点，
  while 循环，判断 x->level[0].forward,不为空，
    判断x->level[0].forward->score =41,循环条件不符，退出到update
    【update[0] = x】，score为21的第二个节点，
```
1. 第一次for循环，i=1。x为跳跃表的头节点。
2. 此时i的值与zsl->level-1相等，所以rank[1]的值为0。
3. header->level[1].forward存在，并且header->level[1].forward->score==1小于要插入的score，所以可以进入while循环，rank[1]=1，x为第一个节点。
4. 第一个节点的第1层的forward指向NULL，所以不会再进入while循环。经过第一次for循环，rank[1]=1。x和update[1]都为第一个节点（score=1）。
5. 经过第二次for循环，i=0。x为跳跃表的第一个节点（score=1）。
6. 此时i的值与zsl->level-1不相等，所以rank[0]等于rank[1]的值，值为1。
7. x->level[0]->forward存在，并且x->level[0].foreard->score==21小于要插入的score，所以可以进入while循环，rank[0]=2。x为第二个节点（score=21）。
8. x->level[0]->forward存在，并且x->level[0].foreard->score==41大于要插入的score，所以不会再进入while，经过第二次for循环，rank[0]=2。x和update[0]都为第二个节点（score=21）。
update和rank赋值后的跳跃表如图3-5所示。
```c
                       +---------+
                       |L63      | ----> NULL
                       |---------|
      rank[0]=2        |...      |
      rank[1]=1        |---------|
                       |L4       | ----> NULL
                       |---------|
                       |L3       | ----> NULL
                       |---------|
                       |L2       |
                       |---------|   1  +---------+   2
                       |L1       | ---> |L1       | ---> NULL
      +--------+       |---------|   1  |---------|  1   +---------+  1   +---------+
      |header  |-+     |L0       | ---> |L0       | ---> |L0       | ---> |L0       |  --> NULL
      |--------| |     |---------|      |---------|      |---------|      |---------|
   +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <--- |backward |
   |  |--------| |  |  |---------|   |  |---------|      |---------|      |---------|
   |  |length=3| |  |--|ele      |   |  |ele      |      |ele      |      |ele      |
   |  |--------| |  |  |---------|  NULL|---------|      |---------|      |---------|
   |  |level=2 | | NULL|score=0  |      |score=1  |      |score=21 |      |score=41 |
   |  +--------+ |     +---------+      +---------+      +---------+      +---------+
   |             |       ^                  ^                ^                ^
   |             |       |                  |                |                |
   |             +-------+                  |                |                |
   |                                    update[1]         update[0]           |
   |__________________________________________________________________________|
```

##### 3.1.3.2.2 调整跳跃表高度

由上文可知，插入节点的高度是随机的，假设要插入节点的高度为3，大于跳跃表的高度2，所以我们需要调整跳跃表的高度。代码如下。
```c
level = zslRandomLevel();
for (i = zsl->level; i < level; i++) {
    rank[i] = 0;
    update[i] = zsl->header;
    update[i]->level[i].span = zsl->length;
}
zsl->level = level;
```
```
rank[0]=2,rank[1]=1
level=3,i = zsl->level 为2，
  rank[2] =0,
  update[2]=zsl->header;
  update[2]->level[2].span = zsl->length = 3;
```
此时，i的值为2，level的值为3，所以只能进入一次for循环。
由于header的第0层到第1层的forward都已经指向了相应的节点，而新添加的节点的高度大于跳跃表的原高度，所以第2层只需要更新header节点即可。
前面我们介绍过，rank是用来更新span的变量，其值是头节点到update[i]所经过的节点数，而此次修改的是头节点，所以rank[2]为0，update[2]一定为头节点。update[2]->level[2].span的值先赋值为跳跃表的总长度，后续在计算新插入节点level[2]的span时会用到此值。
在更新完新插入节点level[2]的span之后会对update[2]->level[2].span的值进行重新计算赋值。

```c
                              +---------+
                              |L63      | ----> NULL
              rank[2]=0       |---------|
              rank[1]=1       |...      |
              rank[0]=2       |---------|
  update[2]->level[2].span=3  |L4       | ----> NULL
                              |---------|
                              |L3       | ----> NULL
                              |---------|  3
                              |L2       | ----> NULL
                              |---------|   1  +---------+   2
                              |L1       | ---> |L1       | ----> NULL
             +--------+       |---------|   1  |---------|  1   +---------+  1   +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | ---> |L0       |  --> NULL
             |--------| |     |---------|      |---------|      |---------|      |---------|
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <--- |backward |
          |  |--------| |  |  |---------|   |  |---------|      |---------|      |---------|
          |  |length=3| |  |--|ele      |   |  |ele      |      |ele      |      |ele      |
          |  |--------| |  |  |---------|  NULL|---------|      |---------|      |---------|
          |  |level=3 | | NULL|score=0  |      |score=1  |      |score=21 |      |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+      +---------+
          |             |       ^  ^               ^                ^                ^
          |             |       |  |               |                |                |
          |             +-------+  |               |                |                |
          |                     update[2]      update[1]         update[0]           |
          |__________________________________________________________________________|
                                             图3-6　调整高度后的跳跃表
```
##### 3.1.3.2.3 插入节点
当update和rank都赋值且节点已创建好后，便可以插入节点了。代码如下。
```c
x = zslCreateNode(level,score,ele);
for (i = 0; i < level; i++) {
    x->level[i].forward = update[i]->level[i].forward;
    update[i]->level[i].forward = x;
    x->level[i].span = update[i]->level[i].span - (rank[0] - rank[i]);
    update[i]->level[i].span = (rank[0] - rank[i]) + 1;
}
```
level的值为3，所以可以执行三次for循环，插入过程如下。

###### 3.1.3.2.3.1 第一次for循环
```
x = createNode(score)
x指向新节点，
for i=0, 0 < level (3),
  x->level[0].forward = update[0]->level[0],forward,
   即x(指向新节点)，的level[0]的forward指向 （update[0]的level[0]的forward，即21的L0的forward，是指向41的节点，）
  update[0]->level[0].forward 指向新插入的x节点，
  x新节点的level[0]的span更新为 update[0]->level[0].span - (rank[0]-rank[0])
    即，x新节点的level[0]的span更新为 指向21节点的level0的span (1)，
  update[0]->level[0].span 更新为 (rank[0]-rank[0])+1,
    即，update[0]的level[0].span更新为1；
```
1. x的level[0]的forward为update[0]的level[0]的forward节点，即x->level[0].forward为score=41的节点。
2. update[0]的level[0]的下一个节点为新插入的节点。
3. rank[0]-rank[0]＝0，update[0]->level[0].span=1，所以x->level[0].span=1。
4. update[0]->level[0].span=0+1=1。
插入节点并更新第0层后的跳跃表如图3-7所示.
```
                                                                                   x新节点
                                                                                 +---------+
                                                                                 |L2       |
                              +---------+                                        +---------+
                              |L63      | ----> NULL                             |L1       |
              rank[2]=0       +---------+                                        +---------+
              rank[1]=1       |...      |                                     +--|L0       |--+
              rank[0]=2       +---------+                                     |  +---------+  |
  update[2]->level[2].span=3  |L4       | ----> NULL                          |  |backward |  |
                              +---------+                                     |  +---------+  |
                              |L3       | ----> NULL                         1|  |ele      |  |1
                              +---------+  3                                  |  +---------+  |
                              |L2       | ----> NULL                          |  |score=31 |  |
                              +---------+   1  +---------+   2                |  +---------+  |
                              |L1       | ---> |L1       | ----> NULL         |               |
             +--------+       +---------+   1  +---------+  1   +---------+   |               |  +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | --+               +->|L0       |  --> NULL
             +--------+ |     +---------+      +---------+      +---------+                      +---------+
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <------------------  |backward |
          |  +--------+ |  |  +---------+   |  +---------+      +---------+                      +---------+
          |  |length=3| |  |--|ele      |   |  |ele      |      |ele      |                      |ele      |
          |  +--------+ |  |  +---------+  NULL+---------+      +---------+                      +---------+
          |  |level=3 | | NULL|score=0  |      |score=1  |      |score=21 |                      |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+                      +---------+
          |             |       ^  ^               ^                ^                                ^
          |             |       |  |               |                |                                |
          |             +-------+  |               |                |                                |
          |                     update[2]      update[1]         update[0]                           |
          |__________________________________________________________________________________________|
                                     图3-7　插入节点并更新第0层后的跳跃表
```

###### 3.1.3.2.3.2 第2次for循环
```
for i=1, 1 < level (3),
  x->level[1].forward = update[1]->level[1],forward,
   即x(指向新节点)，的level[1]的forward指向 (update[1]的level[1]的forward，即1的L1的forward，NULL，)
  update[1]->level[1].forward 指向新插入的x节点，

  x新节点的level[1]的span更新为 update[1]->level[1].span - (rank[0]-rank[1])
    即，x新节点的level[1]的span更新为 指向1节点的level1的span (2)，减去 (rank[0]-rank[1] = 2-1 = 1), 得到1，
  update[1]->level[1].span 更新为  (rank[0]-rank[1])+1,
    即，update[1]的level[1].span更新为2；
```
1. x的level[1]的forward为update[1]的level[1]的forward节点，即x->level[1].forward为NULL。
2. update[1]的level[1]的下一个节点为新插入的节点。
3. rank[0]-rank[1]=1，update[1]->level[1].span=2，所以x->level[1].span=1。
4. update[1]->level[1].span=1+1=2。

插入节点并更新第1层后的跳跃表如图3-8所示。

###### 3.1.3.2.3.3 第3次for循环
```
for i=2, 2 < level (3),
  x->level[2].forward = update[2]->level[2],forward,
   即x(指向新节点)，的level[2]的forward指向 (update[2]的level[2]的forward，即0的L2的forward，NULL，)
  update[2]->level[2].forward 指向新插入的x节点，

  x新节点的level[2]的span更新为 update[2]->level[2].span - (rank[0]-rank[2])
    即，x新节点的level[2]的span更新为 指向0节点的level2的span (3)，减去 (rank[0]-rank[2] = 2-0 = 2), 得到1，
  update[2]->level[2].span 更新为  (rank[0]-rank[2])+1, 2-0+1
    即，update[2]的level[2].span更新为3；
```
1. x的level[2]的forward为update[2]的level[2]的forward节点，即x->level[2].forward为NULL。
2. update[2]的level[2]的下一个节点为新插入的节点。
3. rank[0]-rank[2]=2，因为update[2]->level[2].span=3，所以x->level[2].span=1。
4. update[2]->level[2].span=2+1=3。
插入节点并更新第2层后的跳跃表如图3-9所示。

```
                                                                                   x新节点
                                                                                 +---------+
                                                                                 |L2       |
                              +---------+                                        +---------+  1
                              |L63      | ----> NULL                     +------>|L1       |---->NULL
              rank[2]=0       +---------+                                |       +---------+
              rank[1]=1       |...      |                                |    +->|L0       |--+
              rank[0]=2       +---------+                                |    |  +---------+  |
  update[2]->level[2].span=3  |L4       | ----> NULL                     |    |  |backward |  |
                              +---------+                                |    |  +---------+  |
                              |L3       | ----> NULL                   2 |   1|  |ele      |  |1
                              +---------+  3                             |    |  +---------+  |
                              |L2       | ----> NULL                     |    |  |score=31 |  |
                              +---------+   1  +---------+               |    |  +---------+  |
                              |L1       | ---> |L1       | --------------+    |               |
             +--------+       +---------+   1  +---------+  1   +---------+   |               |  +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | --+               +->|L0       |  --> NULL
             +--------+ |     +---------+      +---------+      +---------+                      +---------+
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <------------------  |backward |
          |  +--------+ |  |  +---------+   |  +---------+      +---------+                      +---------+
          |  |length=3| |  |--|ele      |   |  |ele      |      |ele      |                      |ele      |
          |  +--------+ |  |  +---------+  NULL+---------+      +---------+                      +---------+
          |  |level=3 | | NULL|score=0  |      |score=1  |      |score=21 |                      |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+                      +---------+
          |             |       ^  ^               ^                ^                                ^
          |             |       |  |               |                |                                |
          |             +-------+  |               |                |                                |
          |                     update[2]      update[1]         update[0]                           |
          |__________________________________________________________________________________________|
                                        图3-8　插入节点并更新第1层后的跳跃表
```
```
                                                                                   x新节点
                                                                                 +---------+  1
                                                                   +------------>|L2       |---->NULL
                              +---------+                          |             +---------+  1
                              |L63      | ----> NULL               |     +------>|L1       |---->NULL
              rank[2]=0       +---------+                          |     |       +---------+
              rank[1]=1       |...      |                          |     |    +->|L0       |--+
              rank[0]=2       +---------+                          |     |    |  +---------+  |
  update[2]->level[2].span=3  |L4       | ----> NULL               |     |    |  |backward |  |
                              +---------+                          |     |    |  +---------+  |
                              |L3       | ----> NULL             3 |   2 |   1|  |ele      |  |1
                              +---------+                          |     |    |  +---------+  |
                              |L2       | -------------------------+     |    |  |score=31 |  |
                              +---------+   1  +---------+               |    |  +---------+  |
                              |L1       | ---> |L1       | --------------+    |               |
             +--------+       +---------+   1  +---------+  1   +---------+   |               |  +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | --+               +->|L0       |  --> NULL
             +--------+ |     +---------+      +---------+      +---------+                      +---------+
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <------------------  |backward |
          |  +--------+ |  |  +---------+   |  +---------+      +---------+                      +---------+
          |  |length=3| |  |--|ele      |   |  |ele      |      |ele      |                      |ele      |
          |  +--------+ |  |  +---------+  NULL+---------+      +---------+                      +---------+
          |  |level=3 | | NULL|score=0  |      |score=1  |      |score=21 |                      |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+                      +---------+
          |             |       ^  ^               ^                ^                                ^
          |             |       |  |               |                |                                |
          |             +-------+  |               |                |                                |
          |                     update[2]      update[1]         update[0]                           |
          |__________________________________________________________________________________________|
                                      图3-9　插入节点并更新第2层后的跳跃表
```
###### 3.1.3.2.3.4 新插入节点高度小于原跳跃表高度
新插入节点的高度大于原跳跃表高度，所以下面代码不会运行。
但如果新插入节点的高度小于原跳跃表高度，则从level到zsl->level-1层的update[i]节点forward不会指向新插入的节点，所以不用更新update[i]的forward指针，只将这些level层的span加1即可。代码如下。
```c
for (i = level; i < zsl->level; i++) {
    update[i]->level[i].span++;
}
```

##### 3.1.3.3.4 调整backward
根据update的赋值过程，新插入节点的前一个节点一定是update[0]，由于每个节点的后退指针只有一个，与此节点的层数无关，所以当插入节点不是最后一个节点时，需要更新被插入节点的backward指向update[0]。
如果新插入节点是最后一个节点，则需要更新跳跃表的尾节点为新插入节点。插入节点后，更新跳跃表的长度加1。代码如下。
```c
x->backward = (update[0] == zsl->header) ? NULL : update[0];
if (x->level[0].forward)
    x->level[0].forward->backward = x;
else
    zsl->tail = x;
zsl->length++;
return x;
```
插入新节点后的跳跃表如图3-10所示:
```
                              +---------+
                              |L63      | ----> NULL
              rank[2]=0       +---------+
              rank[1]=1       |...      |
              rank[0]=2       +---------+
  update[2]->level[2].span=3  |L4       | ----> NULL
                              +---------+
                              |L3       | ----> NULL                                 x新节点
                              +---------+                                   3     +---------+
                              |L2       | ------------------------------------->  |L2       | ---> NULL
                              +---------+   1  +---------+                  2     +---------+
                              |L1       | ---> |L1       | -------------------->  |L1       | ---> NULL
             +--------+       +---------+   1  +---------+  1   +---------+ 1     +---------+  1    +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | --->  |L0       | --->  |L0       |  ---> NULL
             +--------+ |     +---------+      +---------+      +---------+       +---------+       +---------+
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <---  |backward | <---  |backward |
          |  +--------+ |  |  +---------+   |  +---------+      +---------+       +---------+       +---------+
          |  |length=4| |  |--|ele      |   |  |ele      |      |ele      |       |ele      |       |ele      |
          |  +--------+ |  |  +---------+  NULL+---------+      +---------+       +---------+       +---------+
          |  |level=3 | | NULL|score=0  |      |score=1  |      |score=21 |       |score=31 |       |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+       +---------+       +---------+
          |             |       ^  ^               ^                ^                                     ^
          |             |       |  |               |                |                                     |
          |             +-------+  |               |                |                                     |
          |                     update[2]      update[1]         update[0]                                |
          |_______________________________________________________________________________________________|
                                           图3-10　插入新节点后的跳跃表
```

#### 3.1.3.3 删除节点
删除节点的步骤：1）查找需要更新的节点；2）设置span和forward。
图3-10中的跳跃表的长度为3，高度为3，此时删除score=31的节点，将此节点记录为x。

```c
/* Delete an element with matching score/element from the skiplist.
 * The function returns 1 if the node was found and deleted, otherwise
 * 0 is returned.
 *
 * If 'node' is NULL the deleted node is freed by zslFreeNode(), otherwise
 * it is not freed (but just unlinked) and *node is set to the node pointer,
 * so that it is possible for the caller to reuse the node (including the
 * referenced SDS string at node->ele). */
int zslDelete(zskiplist *zsl, double score, sds ele, zskiplistNode **node) {
    zskiplistNode *update[ZSKIPLIST_MAXLEVEL], *x;
    int i;

    x = zsl->header;
    for (i = zsl->level-1; i >= 0; i--) {
        while (x->level[i].forward &&
                (x->level[i].forward->score < score ||
                    (x->level[i].forward->score == score &&
                     sdscmp(x->level[i].forward->ele,ele) < 0)))
        {
            x = x->level[i].forward;
        }
        update[i] = x;
    }
    /* We may have multiple elements with the same score, what we need
     * is to find the element with both the right score and object. */
    x = x->level[0].forward;
    if (x && score == x->score && sdscmp(x->ele,ele) == 0) {
        zslDeleteNode(zsl, x, update);
        if (!node)
            zslFreeNode(x);
        else
            *node = x;
        return 1;
    }
    return 0; /* not found */
}

/* Internal function used by zslDelete, zslDeleteByScore and zslDeleteByRank */
void zslDeleteNode(zskiplist *zsl, zskiplistNode *x, zskiplistNode **update) {
    int i;
    for (i = 0; i < zsl->level; i++) {
        if (update[i]->level[i].forward == x) {
            update[i]->level[i].span += x->level[i].span - 1;
            update[i]->level[i].forward = x->level[i].forward;
        } else {
            update[i]->level[i].span -= 1;
        }
    }
    if (x->level[0].forward) {
        x->level[0].forward->backward = x->backward;
    } else {
        zsl->tail = x->backward;
    }
    while(zsl->level > 1 && zsl->header->level[zsl->level-1].forward == NULL)
        zsl->level--;
    zsl->length--;
}
```
##### 3.1.3.3.1 删除时同样 先 查找需要更新的节点
```c
x = zsl->header;
for (i = zsl->level-1; i >= 0; i--) {
    rank[i] = i == (zsl->level-1) ? 0 : rank[i+1];
    while (x->level[i].forward &&
            (x->level[i].forward->score < score ||
                (x->level[i].forward->score == score &&
                sdscmp(x->level[i].forward->ele,ele) < 0)))
    {
        rank[i] += x->level[i].span;
        x = x->level[i].forward;
    }
    update[i] = x;
}
x = x->level[0].forward;
```

```
x = zsl->header;
i=2;i>=0;
  rank[2] = {2 == (3-1?0:...)}, 取0，
  while x->level[2].forward 即 head的L2的forward不为空，
    x->level[2].forward.score 为31 ，== score，
      判断 x->level[2].forward->ele ，ele
  update[2] = x == header
i=1;i>=0
  rank[1] = {1==3-1?0: rank[2]} == 【rank[2]=0】
  while x->level[1].forward 即 head的L1的forward 不为空，
    x->level[1].forward->score  == 1 < score (31)
      rank[1] += x->level[1].span, 即 rank[1] = 0+1 = 1
      x = x->level[1].forward 即x指向了第一个score为1的节点
  while x->level[1].forward 即第一个score为1的节点，L1不为空，
    x->level[1].forward->score == 31 == score (31)
    update[1] = x (score为1的节点)
i=0;i>=0
  rank[0] = {0 == 3-1?0:rank[1]} == 【rank[1] =1】
  while x->level[0].forward 即x(score为1的节点的) L0的forward 不为空，
    x->level[0].forward->score == 21 < score(31)
      rank[0]+=x->level[0].span, 即1 + 1= 2
      x=x->level[0].forward, 即 x指向了score为21的节点，
  while x->level[0].forward 即x(score为21的节点的) L0的forward 不为空，
    x->level[0].forward->score == 31 == score(31)
    update[0]=x (score为21的节点)

x = x->level[0].forward;
x指向score为31的节点
```
查找需要更新的节点要借助update数组，数组的赋值方式与3.3.2中  <a href="#3.1.3.2.1">3.1.3.2.1</a>  update的赋值方式相同，不再赘述。
查找完毕之后，update[2]=header，update[1]为score=1的节点，update[0]为score=21的节点。
删除节点前的跳跃表如<a href="#图3-11">图3-11</a>所示。
<a id="图3-11"></a>

```
                              +---------+
                              |L63      | ----> NULL
                              +---------+
                              |...      |
                              +---------+
                              |L4       | ----> NULL
                              +---------+
                              |L3       | ----> NULL                            需要被删除的节点
                              +---------+                                   3     +---------+
                              |L2       | ------------------------------------->  |L2       | ---> NULL
                              +---------+   1  +---------+                  2     +---------+
                              |L1       | ---> |L1       | -------------------->  |L1       | ---> NULL
             +--------+       +---------+   1  +---------+  1   +---------+ 1     +---------+  1    +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | --->  |L0       | --->  |L0       |  ---> NULL
             +--------+ |     +---------+      +---------+      +---------+       +---------+       +---------+
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <---  |backward | <---  |backward |
          |  +--------+ |  |  +---------+   |  +---------+      +---------+       +---------+       +---------+
          |  |length=4| |  |--|ele      |   |  |ele      |      |ele      |       |ele      |       |ele      |
          |  +--------+ |  |  +---------+  NULL+---------+      +---------+       +---------+       +---------+
          |  |level=3 | | NULL|score=0  |      |score=1  |      |score=21 |       |score=31 |       |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+       +---------+       +---------+
          |             |       ^  ^               ^                ^                                     ^
          |             |       |  |               |                |                                     |
          |             +-------+  |               |                |                                     |
          |                     update[2]      update[1]         update[0]                                |
          |_______________________________________________________________________________________________|
                                           图3-11　删除节点前的跳跃表
```


##### 3.1.3.3.2 设置span和forward
删除节点需要设置update数组中每个节点的span和forward。
假设x的第i层的span值为a，update[i]第i层的span值为b，由于删除了一个节点，所以a+b-1的值就是update[i]第i层的span新值。
update[i]的第i的新forward就是x节点第i层的forward，这个类似链表删除元素的操作。

如果update[i]第i层的forward不为x，说明update[i]的层高大于x的层高，即update[i]第i层指向了指向了x的后续节点或指向NULL。
由于删除了一个节点，所以update[i]的leve[i]的span需要减1。

如果update[i]的forward不为x，在要删除的节点的高度小于跳跃表高度的情况下出现，i大于x高度的节点的forward与x无关，所以这些节点只需更新其span减1即可。

设置span和forward的代码如下。
```c
void zslDeleteNode(zskiplist *zsl, zskiplistNode *x, zskiplistNode **update) {
    int i;
    for (i = 0; i < zsl->level; i++) {
        if (update[i]->level[i].forward == x) {
            update[i]->level[i].span += x->level[i].span - 1;
            update[i]->level[i].forward = x->level[i].forward;
        } else {
            update[i]->level[i].span -= 1;
        }
    }
}
```

```
for i=0; i < 3;
   if update[0]->level[0].forward == x ? yes
      update[0]->level[0].span += x->level[0].apan -1
      ( 即 update[0] score为21的节点L0.span + x的level[0].span 1 - 1)得 1 +1 -1= 1
      update[0]->level[0].forward = x ->level[0].forward:
      ( 即 update[0] score为21的节点 L0.forward = x->level[0].forward 指向score为41的节点)
for i=1; i< 3;
    if update[1]->level[1].forward == x ?yes
      update[1]->level[1].span += x->level[1].span -1
       ( 即 update[1] score为 1的节点L1.span 2+ x的level[1].span 1 - 1)得 2 +1 -1= 2
       update[1]->level[1].forward = x->level[1].forward:
       ( 即 update[1] score为 1的节点 L1.forward = x->level[1].forward 指向NULL)
for i=2; i<3
    if update[2]->level[2].forward == x ? yes
      update[2]->level[2].span = 3 += x的level[2].span 1 -1得 3+1-1 = 3
      update[2]->level[2].forward = x->level[2].forward 得NULL
```

```
                                                                               欲删除节点
                                                                                 +---------+  1
                                                                                 |L2       |---->NULL
                              +---------+                                        +---------+  1
                              |L63      | ----> NULL                             |L1       |---->NULL
                              +---------+                                        +---------+
                              |...      |                 +----------->NULL   +->|L0       |------+
                              +---------+                 |                   |  +---------+      |
                              |L4       | ----> NULL      |      +---->NULL   |  |backward |--+   |
                              +---------+                 |      |            |  +---------+  |   |
                              |L3       | ----> NULL      |3     |2           |  |ele      |  |   |1
                              +---------+                 |      |            |  +---------+  |   |
                              |L2       | ----------------+      |            |  |score=31 |  |   |
                              +---------+   1  +---------+       |            |  +---------+  |   |
                              |L1       | ---> |L1       | ------+            |               |   |
             +--------+       +---------+   1  +---------+  1   +---------+   |       1       |   |  +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | ----------------------+->|L0       |  --> NULL
             +--------+ |     +---------+      +---------+      +---------+   |               |      +---------+
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <-+               +------|backward |
          |  +--------+ |  |  +---------+   |  +---------+      +---------+                          +---------+
          |  |length=3| |  |--|ele      |   |  |ele      |      |ele      |                          |ele      |
          |  +--------+ |  |  +---------+  NULL+---------+      +---------+                          +---------+
          |  |level=3 | | NULL|score=0  |      |score=1  |      |score=21 |                          |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+                          +---------+
          |             |       ^  ^               ^                ^                                    ^
          |             |       |  |               |                |                                    |
          |             +-------+  |               |                |                                    |
          |                     update[2]      update[1]         update[0]                               |
          |______________________________________________________________________________________________|

                                        图3-12　设置span和forward后的跳跃表
```
update节点更新完毕之后，需要更新backward指针、跳跃表高度和长度。
如果x不为最后一个节点，直接将第0层后一个节点的backward赋值为x的backward即可；
否则，将跳跃表的尾指针指向x的backward节点即可。代码如下。

```c
if (x->level[0].forward) {
    x->level[0].forward->backward = x->backward;
else {
    zsl->tail = x->backward;
}
while(zsl->level > 1 && zsl->header->level[zsl->level-1].forward == NULL)
    zsl->level--;
zsl->length--;
```
当删除的x节点是跳跃表的最高节点，并且没有其他节点与x节点的高度相同时，需要将跳跃表的高度减1。
由于删除了一个节点，跳跃表的长度需要减1
删除节点后的跳跃表如图3-13所示。

#### 3.1.3.4 删除跳跃表
获取到跳跃表对象之后，从头节点的第0层开始，通过forward指针逐步向后遍历，每遇到一个节点便将释放其内存。当所有节点的内存都被释放之后，释放跳跃表对象，即完成了跳跃表的删除操作。代码如下。
```c
void zslFree(zskiplist *zsl) {
    zskiplistNode *node = zsl->header->level[0].forward, *next;

    zfree(zsl->header);
    while(node) {
        next = node->level[0].forward;
        zslFreeNode(node);
        node = next;
    }
    zfree(zsl);
}
```

```
                              +---------+
                              |L63      | ----> NULL
                              +---------+
                              |...      |
                              +---------+
                              |L4       | ----> NULL
                              +---------+
                              |L3       | ----> NULL
                              +---------+              3
                              |L2       | -----------------------> NULL
                              +---------+   1  +---------+   2
                              |L1       | ---> |L1       | ------> NULL
             +--------+       +---------+   1  +---------+  1   +---------+    +---------+
             |header  |-+     |L0       | ---> |L0       | ---> |L0       | -->|L0       |  --> NULL
             +--------+ |     +---------+      +---------+      +---------+    +---------+
          +--|tail    | |  +--|backward |   +- |backward | <--- |backward | <--|backward |
          |  +--------+ |  |  +---------+   |  +---------+      +---------+    +---------+
          |  |length=3| |  |--|ele      |   |  |ele      |      |ele      |    |ele      |
          |  +--------+ |  |  +---------+  NULL+---------+      +---------+    +---------+
          |  |level=2 | | NULL|score=0  |      |score=1  |      |score=21 |    |score=41 |
          |  +--------+ |     +---------+      +---------+      +---------+    +---------+
          |             |       ^  ^               ^                ^              ^
          |             |       |  |               |                |              |
          |             +-------+  |               |                |              |
          |                     update[2]      update[1]         update[0]         |
          |________________________________________________________________________|
                                     图3-13　删除节点后的跳跃表
```
### 3.1.4 跳跃表应用
> 在Redis中，跳跃表主要应用于有序集合的底层实现（有序集合的另一种实现方式为压缩列表）。

> Redis的配置文件中关于有序集合底层实现的两个配置。
1. zset-max-ziplist-entries 128：zset采用压缩列表时，元素个数最大值。默认值为128。
2. zset-max-ziplist-value 64：zset采用压缩列表时，每个元素的字符串长度最大值。默认值为64。

#### 3.1.4.2 插入时判断条件采用 跳跃表或压缩列表
> zset添加元素的主要逻辑位于t_zset.c的`zaddGenericCommand`函数中。zset插入第一个元素时，会判断下面两种条件：

- zset-max-ziplist-entries的值是否等于0；
- zset-max-ziplist-value小于要插入元素的字符串长度。

> 满足任一条件Redis就会采用跳跃表作为底层实现，否则采用压缩列表作为底层实现方式。
```c
if (server.zset_max_ziplist_entries == 0 ||
    server.zset_max_ziplist_value < sdslen(c->argv[scoreidx+1]->ptr))
{
    zobj = createZsetObject();//创建跳跃表结构
} else {
    zobj = createZsetZiplistObject();//创建压缩列表结构
}
```
#### 3.1.4.3 默认压缩列表，插入时判断条件并转换为跳跃表
> 一般情况下，不会将zset-max-ziplist-entries配置成0，元素的字符串长度也不会太长，所以在创建有序集合时，默认使用压缩列表的底层实现。

zset新插入元素时，会判断以下两种条件：

- zset中元素个数大于zset_max_ziplist_entries；
- 插入元素的字符串长度大于zset_max_ziplist_value。
当满足任一条件时，Redis便会将zset的底层实现由压缩列表转为跳跃表。代码如下。
```c
// t_zset.c
// int zsetAdd(robj *zobj, double score, sds ele, int *flags, double *newscore)
if (zzlLength(zobj->ptr) > server.zset_max_ziplist_entries)
    zsetConvert(zobj,OBJ_ENCODING_SKIPLIST);
if (sdslen(ele) > server.zset_max_ziplist_value)
    zsetConvert(zobj,OBJ_ENCODING_SKIPLIST);
```
> 值得注意的是，zset在转为跳跃表之后，即使元素被逐渐删除，也不会重新转为压缩列表。

#### 3.1.4.5 源码
```c
void zaddCommand(client *c) {
    zaddGenericCommand(c,ZADD_NONE);
}
/*-----------------------------------------------------------------------------
 * Sorted set commands
 *----------------------------------------------------------------------------*/

/* This generic command implements both ZADD and ZINCRBY. */
void zaddGenericCommand(client *c, int flags) {
    static char *nanerr = "resulting score is not a number (NaN)";
    robj *key = c->argv[1];
    robj *zobj;
    sds ele;
    double score = 0, *scores = NULL;
    int j, elements;
    int scoreidx = 0;
    /* The following vars are used in order to track what the command actually
     * did during the execution, to reply to the client and to trigger the
     * notification of keyspace change. */
    int added = 0;      /* Number of new elements added. */
    int updated = 0;    /* Number of elements with updated score. */
    int processed = 0;  /* Number of elements processed, may remain zero with
                           options like XX. */

    /* Parse options. At the end 'scoreidx' is set to the argument position
     * of the score of the first score-element pair. */
    scoreidx = 2;
    while(scoreidx < c->argc) {
        char *opt = c->argv[scoreidx]->ptr;
        if (!strcasecmp(opt,"nx")) flags |= ZADD_NX;
        else if (!strcasecmp(opt,"xx")) flags |= ZADD_XX;
        else if (!strcasecmp(opt,"ch")) flags |= ZADD_CH;
        else if (!strcasecmp(opt,"incr")) flags |= ZADD_INCR;
        else break;
        scoreidx++;
    }

    /* Turn options into simple to check vars. */
    int incr = (flags & ZADD_INCR) != 0;
    int nx = (flags & ZADD_NX) != 0;
    int xx = (flags & ZADD_XX) != 0;
    int ch = (flags & ZADD_CH) != 0;

    /* After the options, we expect to have an even number of args, since
     * we expect any number of score-element pairs. */
    elements = c->argc-scoreidx;
    if (elements % 2 || !elements) {
        addReply(c,shared.syntaxerr);
        return;
    }
    elements /= 2; /* Now this holds the number of score-element pairs. */

    /* Check for incompatible options. */
    if (nx && xx) {
        addReplyError(c,
            "XX and NX options at the same time are not compatible");
        return;
    }

    if (incr && elements > 1) {
        addReplyError(c,
            "INCR option supports a single increment-element pair");
        return;
    }

    /* Start parsing all the scores, we need to emit any syntax error
     * before executing additions to the sorted set, as the command should
     * either execute fully or nothing at all. */
    scores = zmalloc(sizeof(double)*elements);
    for (j = 0; j < elements; j++) {
        if (getDoubleFromObjectOrReply(c,c->argv[scoreidx+j*2],&scores[j],NULL)
            != C_OK) goto cleanup;
    }

    /* Lookup the key and create the sorted set if does not exist. */
    zobj = lookupKeyWrite(c->db,key);
    if (zobj == NULL) {
        if (xx) goto reply_to_client; /* No key + XX option: nothing to do. */
        if (server.zset_max_ziplist_entries == 0 ||
            server.zset_max_ziplist_value < sdslen(c->argv[scoreidx+1]->ptr))
        {
            zobj = createZsetObject(); //创建跳跃表结构
        } else {
            zobj = createZsetZiplistObject(); //创建压缩列表结构
        }
        dbAdd(c->db,key,zobj);
    } else {
        if (zobj->type != OBJ_ZSET) {
            addReply(c,shared.wrongtypeerr);
            goto cleanup;
        }
    }
    for (j = 0; j < elements; j++) {
        double newscore;
        score = scores[j];
        int retflags = flags;

        ele = c->argv[scoreidx+1+j*2]->ptr;
        int retval = zsetAdd(zobj, score, ele, &retflags, &newscore);
        if (retval == 0) {
            addReplyError(c,nanerr);
            goto cleanup;
        }
        if (retflags & ZADD_ADDED) added++;
        if (retflags & ZADD_UPDATED) updated++;
        if (!(retflags & ZADD_NOP)) processed++;
        score = newscore;
    }
    server.dirty += (added+updated);

reply_to_client:
    if (incr) { /* ZINCRBY or INCR option. */
        if (processed)
            addReplyDouble(c,score);
        else
            addReply(c,shared.nullbulk);
    } else { /* ZADD. */
        addReplyLongLong(c,ch ? added+updated : added);
    }

cleanup:
    zfree(scores);
    if (added || updated) {
        signalModifiedKey(c->db,key);
        notifyKeyspaceEvent(NOTIFY_ZSET,
            incr ? "zincr" : "zadd", key, c->db->id);
    }
}
```

## 3.3 压缩列表


> 压缩列表ziplist本质上就是一个字节数组，是Redis为了节约内存而设计的一种线性数据结构，可以包含多个元素，每个元素可以是一个字节数组或一个整数。

> Redis的有序集合、散列和列表都直接或者间接使用了压缩列表。
> 当有序集合或散列表的元素个数比较少，且元素都是短字符串时，Redis便使用压缩列表作为其底层数据存储结构。
> 列表使用快速链表（quicklist）数据结构存储，而快速链表就是双向链表与压缩列表的组合。

> 使用如下命令创建一个散列键并查看其编码。
```redis
127.0.0.1:6379> hmset person name zhangsan gender 1 age 22
OK
127.0.0.1:6379> object encoding person
"ziplist"
```
### 3.3.1 压缩列表的存储结构
#### 3.3.1.1 压缩列表结构 字段
Redis使用字节数组表示一个压缩列表，压缩列表结构示意如图4-1所示。
```
+-------+-------+-------+-------+-------+- - - -+-------+
|zlbytes| zltail| zllen | entry1| entry2|       | zlend |
+-------+-------+-------+-------+-------+- - - -+-------+
               图4-1 压缩列表结构示意
```

图4-1中各字段的含义如下。

1. zlbytes： 压缩列表的字节长度，占4个字节，因此压缩列表最多有232 -1个字节。
2. zltail： 压缩列表尾元素相对于压缩列表起始地址的偏移量，占4个字节。
3. zllen： 压缩列表的元素个数，占2个字节。zllen无法存储元素个数超过65535（216 -1）的压缩列表，必须遍历整个压缩列表才能获取到元素个数。
4. entryX： 压缩列表存储的元素，可以是字节数组或者整数，长度不限。entry的编码结构将在后面详细介绍。
5. zlend： 压缩列表的结尾，占1个字节，恒为0xFF。

假设`char*zl`指向压缩列表首地址，Redis可通过以下宏定义实现压缩列表各个字段的存取操作。
```c
#define intrev32ifbe(v) (v)

//ziplist.c
//zl指向zlbytes字段
#define ZIPLIST_BYTES(zl)       (*((uint32_t*)(zl)))

//zl+4指向zltail字段
#define ZIPLIST_TAIL_OFFSET(zl) (*((uint32_t*)((zl)+sizeof(uint32_t))))

//zl+zltail指向尾元素首地址；intrev32ifbe使得数据存取统一采用小端法
#define ZIPLIST_ENTRY_TAIL(zl)  ((zl)+intrev32ifbe(ZIPLIST_TAIL_OFFSET(zl)))

//zl+8指向zllen字段
#define ZIPLIST_LENGTH(zl)      (*((uint16_t*)((zl)+sizeof(uint32_t)*2)))

//压缩列表最后一个字节即为zlend字段
#define ZIPLIST_ENTRY_END(zl)   ((zl)+intrev32ifbe(ZIPLIST_BYTES(zl))-1)
```
#### 3.3.1.2 列表元素结构
了解了压缩列表的基本结构，我们可以很容易地获得压缩列表的字节长度、元素个数等，那么如何遍历压缩列表呢？
对于任意一个元素，我们如何判断其存储的是什么类型呢？我们又如何获取字节数组的长度呢？

回答这些问题之前，需要先了解压缩列表元素的编码结构，如图4-2所示。
```
+-----------------------+---------------+---------------+
| previous entry length |   encoding    |  content      |
+-----------------------+---------------+---------------+
               图4-2　压缩列表元素的结构示意
```
- previous entry length :
    `previous_entry_length`字段表示前一个元素的字节长度，占1个或者5个字节，
    当前一个元素的长度小于254字节时，用1个字节表示；
    当前一个元素的长度大于或等于254字节时，用5个字节来表示。
    而此时`previous_entry_length`字段的第1个字节是固定的0xFE，后面4个字节才真正表示前一个元素的长度。
    > 假设已知当前元素的首地址为p，那么`p-previous_entry_length`就是前一个元素的首地址，从而实现压缩列表从尾到头的遍历。
- encoding:
    encoding字段表示当前元素的编码，即content字段存储的数据类型（整数或者字节数组），
    为了节约内存，encoding字段同样长度可变。压缩列表元素的编码如表4-1所示。
- 数据内容存储在content字段。

表4-1　压缩列表元素的编码

|                            encoding编码                            | encoding长度 |            content类型             |
| ------------------------------------------------------------------ | ------------ | ---------------------------------- |
| 00 bbbbbb(6比特表示content长度)                                     | 1字节        | 最大长度为63的字节数组               |
| 01 bbbbbb xxxxxxxx(14比特表示content长度)                           | 2字节        | 最大长度为2^14-1的字节数组           |
| 10------ aaaaaaaa bbbbbbbb cccccccc dddddddd(32比特表示content长度) | 5字节        | 最大长度为2^32-1的字节数组           |
| 11 00 0000                                                         | 1字节        | int16整数                          |
| 11 01 0000                                                         | 1字节        | int32整数                          |
| 11 10 0000                                                         | 1字节        | int64整数                          |
| 11 11 0000                                                         | 1字节        | 24位整数                           |
| 11 11 1110                                                         | 1字节        | 8位整数                            |
| 11 11 xxxx                                                         | 1字节        | 没有content字段；xxxx表示0～12的整数 |

> 可以看出，根据**encoding字段**`第1个字节的前2位`，可以判断content字段存储的是整数或者字节数组（及其最大长度）。
> 当content存储的是`字节数组`时，后续字节标识字节数组的实际长度；
> 当content存储的是`整数`时，可根据第3、第4位判断整数的具体类型。
> 而当encoding字段标识当前元素存储的是0～12的立即数时，数据直接存储在encoding字段的最后4位，此时没有content字段。

> 参照encoding字段的编码表格，Redis预定义了以下常量对应encoding字段的各编码类型：
```c
#define ZIP_STR_06B (0 << 6)
#define ZIP_STR_14B (1 << 6)
#define ZIP_STR_32B (2 << 6)
#define ZIP_INT_16B (0xc0 | 0<<4)
#define ZIP_INT_32B (0xc0 | 1<<4)
#define ZIP_INT_64B (0xc0 | 2<<4)
#define ZIP_INT_24B (0xc0 | 3<<4)
#define ZIP_INT_8B 0xfe
```
注：

|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8   |  9   |  16   |   32   |   48   | 64(1<<6) | 128(2<<6) | 192(0xc0) | 254（0xfe） |
| --- | --- | --- | --- | --- | --- | --- | --- | ---- | ---- | ----- | ------ | ------ | -------- | --------- | --------- | ----------- |
| 0   | 1   | 10  | 11  | 100 | 101 | 110 | 111 | 1000 | 1001 | 10000 | 100000 | 110000 | 1000000  | 10000000  | 11000000  | 11111110    |


|    类型     |       宏       | 十进制 |  二进制   |                          encoding                           | encoding长度 |       content类型        |
| ----------- | -------------- | ----- | -------- | ----------------------------------------------------------- | ------------ | ------------------------ |
| ZIP_STR_06B | 0<<6           | 0     | 0        | 00 xx xxxx                             (6比特表示content长度) | 1字节 8位    | 最大长度为63的字节数组     |
| ZIP_STR_14B | 1<<6           | 64    | 1000000  | 01 xx xxxx xxxxxxxx                   (14比特表示content长度) | 2字节 16位   | 最大长度为2^14-1的字节数组 |
| ZIP_STR_32B | 2<<6           | 128   | 10000000 | 01 xx xxxx xxxxxxxx xxxxxxxx xxxxxxxx (32比特表示content长度) | 5字节 40位   | 最大长度为2^32-1的字节数组 |
| ZIP_INT_16B | (0xc0 \| 0<<4) | 192   | 11000000 | 11 xx xxxx                                                  | 1字节 8位    | int16整数                |
| ZIP_INT_32B | (0xc0 \| 1<<4) | 208   | 11010000 | 11 01 xxxx                                                  | 1字节 8位    | int32整数                |
| ZIP_INT_64B | (0xc0 \| 2<<4) | 224   | 11100000 | 11 10 xxxx                                                  | 1字节 8位    | int64整数                |
| ZIP_INT_24B | (0xc0 \| 3<<4) | 240   | 11110000 | 11 11 xxxx                                                  | 1字节 8位    | 24位整数                 |
| ZIP_INT_8B  | 0xfe           | 254   | 11111110 | 11 11 1110                                                  | 1字节 8位    | 8位整数                  |

### 3.3.2 结构体
#### 3.3.2.1 结构体元素
3.3.1 节介绍了压缩列表的存储结构，我们发现对于压缩列表的任意元素，获取前一个元素的长度、判断存储的数据类型、获取数据内容都需要经过复杂的解码运算。解码后的结果应该被缓存起来，为此定义了结构体zlentry，用于表示解码后的压缩列表元素。
```c
typedef struct zlentry {
    unsigned int prevrawlensize;
    unsigned int prevrawlen;

    unsigned int lensize;
    unsigned int len;
    unsigned char encoding;

    unsigned int headersize;

    unsigned char *p;
} zlentry;
```
> 结构体zlentry定义了7个字段，而3.3.1(4.1)节显示每个元素只包含3个字段。

回顾压缩列表元素的编码结构，可变因素实际上不止3个：
previous_entry_length字段的长度（`prevrawlensize`）、
previous_entry_length字段存储的内容（`prevrawlen`）、
encoding字段的长度（`lensize`）、
encoding字段的内容（`len`表示元素数据内容的长度，`encoding`表示数据类型）
当前元素首地址（`p`）；
而`headersize`则表示当前元素的首部长度，即previous_entry_length字段长度与encoding字段长度之和。

#### 3.3.2.1 解压元素
函数zipEntry用来解码压缩列表的元素，存储于zlentry结构体。
```c
void zipEntry(unsigned char *p, zlentry *e) {
    ZIP_DECODE_PREVLEN(p, e->prevrawlensize, e->prevrawlen);
    ZIP_DECODE_LENGTH(p + e->prevrawlensize, e->encoding, e->lensize, e->len);
    e->headersize = e->prevrawlensize + e->lensize;
    e->p = p;
}
```

解码主要可以分为以下两个步骤。

##### 3.3.2.1.1 解码previous_entry_length字段，此时入参ptr指向元素首地址。
```c
#define ZIP_BIG_PREVLEN 254

#define ZIP_DECODE_PREVLEN(ptr, prevlensize, prevlen) do {
    if ((ptr)[0] < ZIP_BIG_PREVLEN) {
        (prevlensize) = 1;
        (prevlen) = (ptr)[0];
    } else {
        (prevlensize) = 5;
        memcpy(&(prevlen), ((char*)(ptr)) + 1, 4);
        memrev32ifbe(&prevlen);
    }
} while(0);
```
##### 3.3.2.1.2 解码encoding字段逻辑，此时入参ptr指向元素首地址偏移previous_entry_length字段长度的位置。
<a id="3.3.2.1.2"></a>
```c
#define ZIP_STR_MASK 0xc0

#define ZIP_DECODE_LENGTH(ptr, encoding, lensize, len) do {
    (encoding) = (ptr[0]);
    // ptr[0]<11000000说明是字节数组，前两个比特为字节数组编码类型
    if ((encoding) < ZIP_STR_MASK) (encoding) &= ZIP_STR_MASK;
    if ((encoding) < ZIP_STR_MASK) {
        if ((encoding) == ZIP_STR_06B) {
            (lensize) = 1;
            (len) = (ptr)[0] & 0x3f;
        } else if ((encoding) == ZIP_STR_14B) {
            (lensize) = 2;
            (len) = (((ptr)[0] & 0x3f) << 8) | (ptr)[1];
        } else if ((encoding) == ZIP_STR_32B) {
            (lensize) = 5;
            (len) = ((ptr)[1] << 24) |
                    ((ptr)[2] << 16) |
                    ((ptr)[3] <<  8) |
                    ((ptr)[4]);
        } else {
            panic("Invalid string encoding 0x%02X", (encoding));
        }
    } else {
        (lensize) = 1;
        (len) = zipIntSize(encoding);
    }
} while(0);
```
字节数组只根据ptr[0]的前2个比特即可判断类型，而判断整数类型需要ptr[0]的前4个比特，代码如下。

```c
unsigned int zipIntSize(unsigned char encoding) {
    switch(encoding) {
    case ZIP_INT_8B:  return 1;
    case ZIP_INT_16B: return 2;
    case ZIP_INT_24B: return 3;
    case ZIP_INT_32B: return 4;
    case ZIP_INT_64B: return 8;
    }

    //0～12立即数
    if (encoding >= ZIP_INT_IMM_MIN && encoding <= ZIP_INT_IMM_MAX)
        return 0;
    panic("Invalid integer encoding 0x%02X", encoding);
    return 0;
}
```

### 3.3.3 基本操作
#### 3.3.3.1 创建压缩列表
> 创建压缩列表的API定义如下，函数无输入参数，返回参数为压缩列表首地址。

`unsigned char *ziplistNew(void);`
创建空的压缩列表，只需要分配初始存储空间11(4+4+2+1)个字节，并对zlbytes、zltail、zllen和zlend字段初始化即可。

```
unsigned char *ziplistNew(void) {
    //ZIPLIST_HEADER_SIZE = zlbytes + zltail + zllen;
    unsigned int bytes = ZIPLIST_HEADER_SIZE+1;
    unsigned char *zl = zmalloc(bytes);
    ZIPLIST_BYTES(zl) = intrev32ifbe(bytes);
    ZIPLIST_TAIL_OFFSET(zl) = intrev32ifbe(ZIPLIST_HEADER_SIZE);
    ZIPLIST_LENGTH(zl) = 0;

    //结尾标识0XFF
    zl[bytes-1] = ZIP_END;
    return zl;
}
```
#### 3.3.3.2 插入元素
压缩列表插入元素的API定义如下，函数输入参数zl表示压缩列表首地址，p指向元素插入位置，s表示数据内容，slen表示数据长度，返回参数为压缩列表首地址。
```c
unsigned char *ziplistInsert(unsigned char *zl, unsigned char *p,
                             unsigned char *s, unsigned int slen);
```
插入元素可以简要分为3个步骤：
①将元素内容编码；
②重新分配空间；
③复制数据。

下面分别讲解每个步骤的实现逻辑。

##### 3.3.3.2.1 <a id="3.3.3.2.1">元素内容编码
</a>
> 编码即计算`previous_entry_length`字段、`encoding`字段和`content`字段的内容。
> 那么如何获取前一个元素的长度呢？此时就需要根据元素的插入位置分情况讨论。插入元素位置示意如图4-3所示。

```
                      插入位置P0
                        |
+-------+-------+-------+-------+
|zlbytes| zltail| zllen | zlend |
+-------+-------+-------+-------+

                                    插入位置P1                插入位置P2
                                        |                        |
+-------+-------+-------+- - - -+-------+--------+- - - -+-------+-------+
|zlbytes| zltail| zllen | . . . | entryX|entryX+1| . . . | entryN| zlend |
+-------+-------+-------+- - - -+-------+--------+- - - -+-------+-------+
                           图4-3　插入元素位置示意
```

1. 当压缩列表为空、插入位置为P0时，不存在前一个元素，即前一个元素的长度为0。
2. 当插入位置为P1时，需要获取entryX元素的长度，而entryX+1元素的previous_entry_length字段存储的就是entryX元素的长度，比较容易获取。
3. 当插入位置为P2时，需要获取entryN元素的长度，entryN是压缩列表的尾元素，计算元素长度时需要将其3个字段长度相加，函数实现如下。

```c
unsigned int zipRawEntryLength(unsigned char *p) {
    unsigned int prevlensize, encoding, lensize, len;
    ZIP_DECODE_PREVLENSIZE(p, prevlensize);
    ZIP_DECODE_LENGTH(p + prevlensize, encoding, lensize, len);
    return prevlensize + lensize + len;
}
```

其中`ZIP_DECODE_LENGTH`的逻辑在 <a href="#3.3.2.1.2">3.3.2.1.2</a> (4.2节)已经讲过，`ZIP_DECODE_PREVLENSIZE`的逻辑与`ZIP_DECODE_PREVLEN`基本相同。

encoding字段标识的是当前元素存储的数据类型和数据长度。
编码时首先尝试将数据内容解析为整数，
- 如果解析成功，则按照压缩列表整数类型编码存储；
- 如果解析失败，则按照压缩列表字节数组类型编码存储。
```c
if (zipTryEncoding(s,slen,&value,&encoding)) {
    reqlen = zipIntSize(encoding);
} else {
    reqlen = slen;
}
reqlen += zipStorePrevEntryLength(NULL,prevlen);
reqlen += zipStoreEntryEncoding(NULL,encoding,slen);
```
上述程序尝试按照整数解析新添加元素的数据内容，数值存储在变量value中，编码存储在变量encoding中。
如果解析成功，还需要计算整数所占字节数。

变量reqlen最终存储的是当前元素所需空间大小，初始赋值为元素content字段所需空间大小，再累加previous_entry_length和encoding字段所需空间大小。

##### 3.3.3.2.2 重新分配空间

> 由于新插入了元素，压缩列表所需空间增大，因此需要重新分配存储空间。
那么空间大小是不是添加元素前的压缩列表长度与新添加元素长度之和呢？并不完全是。压缩列表长度变化示意如图4-4所示。

插入元素前，`entryX`元素的长度为`128字节`，`entryX+1`元素的`previous_entry_length`字段占`1个字节`；
添加元素`entryNEW`，元素长度为`1024字节`，此时`entryX+1`元素的`previous_entry_length`字段需要占`5个字节`，即压缩列表的长度不仅增加了1024个字节，还要加上`entryX+1`元素扩展的4个字节。
而entryX+1元素的长度可能增加4个字节、减少4个字节或不变。

由于重新分配了空间，新元素插入的位置指针P会失效，可以预先计算好指针P相对于压缩列表首地址的偏移量，待分配空间之后再偏移即可。
```
                    P
                    |                         entryX+1
                    | __________________________^__________________________
                    |/                                                      \
        +-----------+-----------------------+---------------+---------------+
插入前  | entryX    | previous entry length |   encoding    |  content      |
        +-----------+-----------------------+---------------+---------------+
         \         / \                     /
           128字节          1字节

                    P
                    |                         entryNEW(1024字节)                                      entryX+1
                    |  ________________________^__________________________     _________________________^__________________________
                    |/                                                     \ /                                                      \
        +-----------+-----------------------+---------------+---------------+ -----------------------+---------------+---------------+
插入后  | entryX    | previous entry length |   encoding    |  content      |  previous entry length |   encoding    |  content      |
        +-----------+-----------------------+---------------+---------------+ -----------------------+---------------+---------------+
         \         / \                     /                                 \                      /
           128字节          1字节                                                   5字节

                           图4-4　压缩列表长度变化示意
```

```c
size_t curlen = intrev32ifbe(ZIPLIST_BYTES(zl));
int forcelarge = 0;
nextdiff = (p[0] != ZIP_END) ? zipPrevLenByteDiff(p,reqlen) : 0;
if (nextdiff == -4 && reqlen < 4) {
    nextdiff = 0;
    forcelarge = 1;
}
//存储偏移量
offset = p-zl;
//调用realloc重新分配空间
zl = ziplistResize(zl,curlen+reqlen+nextdiff);
//重新偏移到插入位置P
p = zl+offset;
```

nextdiff与forcelarge在这里有什么用呢？
分析ziplistResize函数的第二个参数，curlen表示插入元素前压缩列表的长度；
reqlen表示新插入元素的长度；
而nextdiff表示entryX+1元素长度的变化，取值可能为0（长度不变）、4（长度增加4）或-4（长度减少4）。

我们再思考下，当nextdiff=4而reqlen<4时会发生什么呢？
没错，插入元素导致压缩列表所需空间减小了，即函数ziplistResize内部调用realloc重新分配的空间小于指针zl指向的空间。
我们知道realloc重新分配空间时，返回的地址可能不变（当前位置有足够的内存空间可供分配），当重新分配的空间减小时，realloc可能会将多余的空间回收，导致数据丢失。
因此需要避免这种情况的发生，即重新赋值nextdiff=0，同时使用forcelarge标记这种情况。

那么，nextdiff=-4时，reqlen会小于4吗？
nextdiff=-4说明插入元素之前entryX+1元素的previous_entry_length字段的长度是5字节，即entryX元素的总长度大于或等于254字节，所以entryNEW元素的previous_entry_length字段同样需要5个字节，即entryNEW元素的总长度肯定是大于5个字节的，reqlen又怎么会小于4呢？
正常情况下是不会出现这种情况的，但是由于存在连锁更新（将在4.4节介绍），可能会出现nextdiff=-4但entryX元素的总长度小于254字节的情况，此时reqlen可能会小于4。

##### 3.3.3.2.3 数据复制

重新分配空间之后，需要将位置P后的元素移动到指定位置，将新元素插入到位置P。
我们假设entryX+1元素的长度增加4（即nextdiff=4），此时压缩列表数据复制示意如图4-5所示。
```
                    P
                    |         entryX+1
                    |  __________^__________
                    |/                       \
        +-----------+---+-----+---------------+
插入前  | entryX    |   |     |  content      |
        +-------*---+---+-----+---------------+
         \        /* \ /                          *
           12字节     *1字节                         *
                         *                              *
                            *                              *
                               *                              *
                                  *                              *
                                     *                              *
                                        *                              *
                    P                      *                              *
                    |      entryNEW(1024字节)                entryX+1        *
                    | __________^_____________*    _____________^_____________  *
                    |/                          \ /                            \   *
        +-----------+-----+------+---------------+----------------+---+---------------+
插入后  | entryX    |     |      |               |                |   |               |
        +-----------+-----+------+---------------+----------------+---+---------------+
         \         / \                         /  \              /
           12字节         插入数据块                   5字节

                        图4-5　压缩列表数据复制示意
```

从图4-5中可以看到，位置P后的所有元素都需要移动，移动的偏移量是待插入元素entryNEW的长度，移动的数据块长度是位置P后所有元素的长度之和加上nextdiff的值，数据移动之后还需要更新entryX+1元素的previous_entry_length 字段。

```c
//为什么减1呢？zlend结束表示恒为0xFF，不需要移动
memmove(p+reqlen,p-nextdiff,curlen-offset-1+nextdiff);

//更新entryX+1元素的previous_entry_length字段
if (forcelarge)
    //entryX+1元素的previous_entry_length字段依然占5个字节;
    //但是entryNEW元素的长度小于4字节
    zipStorePrevEntryLengthLarge(p+reqlen,reqlen);
else
    zipStorePrevEntryLength(p+reqlen,reqlen);
//更新zltail字段
ZIPLIST_TAIL_OFFSET(zl) =
    intrev32ifbe(intrev32ifbe(ZIPLIST_TAIL_OFFSET(zl))+reqlen);
zipEntry(p+reqlen, &tail);
if (p[reqlen+tail.headersize+tail.len] != ZIP_END) {
    ZIPLIST_TAIL_OFFSET(zl) =
        intrev32ifbe(intrev32ifbe(ZIPLIST_TAIL_OFFSET(zl))+nextdiff);
}

//更新zllen字段
ZIPLIST_INCR_LENGTH(zl,1);
```

#### 3.3.3.3 删除元素
压缩列表删除元素的API定义如下，
函数输入参数zl指向压缩列表首地址；
*p指向待删除元素的首地址（参数p同时可以作为输出参数）；
返回参数为压缩列表首地址。
`unsigned char *ziplistDelete(unsigned char *zl, unsigned char **p);`

ziplistDelete函数只是简单调用底层_ziplistDelete函数实现删除功能。
_ziplistDelete函数可以同时删除多个元素，输入参数p指向的是首个待删除元素的地址；num表示待删除元素数目。
```c
unsigned char *ziplistDelete(unsigned char *zl, unsigned char **p) {
    size_t offset = *p-zl;
    zl = __ziplistDelete(zl,*p,1);
    *p = zl+offset;
    return zl;
}
```
删除元素同样可以简要分为三个步骤：
- ① 计算待删除元素的总长度；
- ② 数据复制；
- ③ 重新分配空间。

下面分别讨论每个步骤的实现逻辑。

##### 3.3.3.3.1 计算待删除元素的总长度 。
`zipRawEntryLength`函数在<a href="#3.3.3.2.1">3.3.3.2.1</a>(4.3.2节)已经讲过，这里不再详述；
```c
//解码第一个待删除元素
zipEntry(p, &first);

//遍历所有待删除元素，同时指针p向后偏移
for (i = 0; p[0] != ZIP_END && i < num; i++) {
    p += zipRawEntryLength(p);
    deleted++;
}
//totlen即为待删除元素总长度
totlen = p-first.p;
```

##### 3.3.3.3.2 数据复制 。
第1步完成之后，指针first与指针p之间的元素都是待删除的。
当指针p恰好指向zlend字段时，不再需要复制数据，只需要更新尾节点的偏移量即可。
下面分析另一种情况，即指针p指向的是某一个元素，而不是zlend字段。

删除元素时，压缩列表所需空间减小，减小的量是否仅为待删除元素的总长度呢？
答案同样是否定的。举个简单的例子，图4-6是经过第1步之后的压缩列表示意。

删除元素entryX+1到元素entryN-1之间的N-X-1个元素，元素entryN-1的长度为12字节，因此元素entryN的previous_entry_length字段占1个字节；
删除这些元素之后，entryX成为了entryN的前一个元素，元素entryX的长度为512字节，因此元素entryN的previous_entry_length字段需要占5个字节，即删除元素之后的压缩列表的总长度还与元素entryN长度的变化量有关。

```
                                         first                         P
                                           |                           |
                                  512字节  |                    12字节 |1字节
+-------+-------+-------+- - - -+----------+- - - - -+- - - -+---------+-----+-----+---------+- - - - -+-------+
|zlbytes| zltail| zllen | . . . | entryX   | entryX+1|       | entryN-1|     |     |         |         | zlend |
+-------+-------+-------+- - - -+----------+- - - - -+- - - -+---------+-----+-----+---------+- - - - -+-------+
                                                                        \    entryN        /


                                           |
                                  512字节  |5字节
+-------+-------+-------+- - - -+----------+---------+-----+---------+- - - - -+-------+
|zlbytes| zltail| zllen | . . . | entryX   |         |     |         |         | zlend |
+-------+-------+-------+- - - -+----------+---------+-----+---------+- - - - -+-------+
                                            \        entryN         /
                                     图4-6　压缩列表删除元素示意
```

```c
//计算元素entryN长度的变化量
nextdiff = zipPrevLenByteDiff(p,first.prevrawlen);
//更新元素entryN的previous_entry_length字段
p -= nextdiff;
zipStorePrevEntryLength(p,first.prevrawlen);
//更新zltail
ZIPLIST_TAIL_OFFSET(zl) =
    intrev32ifbe(intrev32ifbe(ZIPLIST_TAIL_OFFSET(zl))-totlen);
zipEntry(p, &tail);
if (p[tail.headersize+tail.len] != ZIP_END) {
    ZIPLIST_TAIL_OFFSET(zl) =
        intrev32ifbe(intrev32ifbe(ZIPLIST_TAIL_OFFSET(zl))+nextdiff);
}
//数据复制
memmove(first.p,p,
    intrev32ifbe(ZIPLIST_BYTES(zl))-(p-zl)-1);
```
与4.3.2节中更新zltail字段相同，当entryN元素就是尾元素时，只需要更新一次尾元素的偏移量；
但是当entryN元素不是尾元素且entryN元素的长度发生了改变时，尾元素偏移量还需要加上nextdiff的值。

##### 3.3.3.3.3 重新分配空间 。
逻辑与 <a href="#3.3.3.2">3.3.3.2</a>(4.3.2)中 插入元素的逻辑基本类似，这里不再赘述。代码如下。
```c
offset = first.p-zl;
zl = ziplistResize(zl, intrev32ifbe(ZIPLIST_BYTES(zl))-totlen+nextdiff);
p = zl+offset;
ZIPLIST_INCR_LENGTH(zl,-deleted);
```
思考一下 ：在<a href="#3.3.3.2">3.3.3.2</a>(4.3.2)中我们提到，调用ziplistResize函数重新分配空间时，如果重新分配的空间小于指针zl指向的空间时，可能会出现问题。而删除元素时，压缩列表的长度肯定是减小的。

因为删除元素时，先复制数据，再重新分配空间，即调用ziplistResize函数时，多余的那部分空间存储的数据已经被复制了，此时回收这部分空间并不会造成数据丢失。

#### 3.3.3.4 遍历压缩列表
遍历就是从头到尾（后向遍历）或者从尾到头（前向遍历）访问压缩列表中的每个元素。
压缩列表的遍历API定义如下，
函数输入参数zl指向压缩列表首地址，
p指向当前访问元素的首地址；
ziplistNext函数返回后一个元素的首地址，
ziplistPrev返回前一个元素的首地址。

```
//后向遍历
unsigned char *ziplistNext(unsigned char *zl, unsigned char *p);
//前向遍历
unsigned char *ziplistPrev(unsigned char *zl, unsigned char *p);
```

压缩列表每个元素的previous_entry_length字段存储的是前一个元素的长度，因此压缩列表的前向遍历相对简单，表达式p-previous_entry_length即可获取前一个元素的首地址，这里不做详述。
后向遍历时，需要解码当前元素，计算当前元素的长度，才能获取后一个元素首地址；
ziplistNext函数实现如下。
```c
unsigned char *ziplistNext(unsigned char *zl, unsigned char *p) {
    //zl参数无用；这里只是为了避免警告
    ((void) zl);
    if (p[0] == ZIP_END) {
        return NULL;
    }
    p += zipRawEntryLength(p);
    if (p[0] == ZIP_END) {
        return NULL;
    }
    return p;
}
```
其中`zipRawEntryLength`函数在 <a href="#3.3.3.2">3.3.3.2</a>(4.3.2) 节中已经讲过，这里不再赘述。

### 3.3.4 连锁更新
压缩列表连锁更新示意如图4-7所示，
删除压缩列表zl1位置P1的元素entryX，或者在压缩列表zl2位置P2插入元素entryY时，
会出现什么情况呢？
```
                                           P1
                                           |
                                | 512字节  |128字节| 253字节 | 253字节 |
+-------+-------+-------+- - - -+----------+-------+---------+---------+----------+-------+
|zlbytes| zltail| zllen | . . . | entryX-1 | entryX| entryX+1| entryX+2|  . . .   | zlend |
+-------+-------+-------+- - - -+----------+-------+---------+---------+----------+-------+

                                           P2
                                           |
                                | 128字节  | 253字节 | 253字节 |
+-------+-------+-------+- - - -+----------+---------+---------+----------+-------+
|zlbytes| zltail| zllen | . . . | entryY-1 | entryY+1| entryY+2|  . . .   | zlend |
+-------+-------+-------+- - - -+----------+---------+---------+----------+-------+
                                         /  \
                                       /     \
                                      +-------+
                                      | entryX|
                                      +-------+
                                       512字节
```
压缩列表zl1中，元素entryX之后的所有元素（entryX+1、entryX+2等）的长度都是253字节，显然这些元素`previous_entry_length`字段的长度都是1字节。
当删除元素entryX时，元素entryX+1的前驱节点改为元素entryX-1，长度为512字节，元素entryX+1的`previous_entry_length`字段需要5字节才能存储元素entryX-1的长度，则元素entryX+1的长度需要扩展至257字节；
而由于元素entryX+1长度的增大，元素entryX+2的`previous_entry_length`字段同样需要改变。
依此类推，由于删除了元素entryX，之后的所有元素（entryX+1、entryX+2等）的长度都必须扩展，而每次扩展都将重新分配内存，导致效率很低。
压缩列表zl2中，插入元素entryY时同样会出现这种情况，称为连锁更新。

从以上分析可以看出，连锁更新会导致多次重新分配内存及数据复制，效率很低。
但是出现这种情况的概率是很低的，因此对于删除元素和插入元素操作，Redis并没有为了避免连锁更新而采取措施。
Redis只是在删除元素和插入元素操作的末尾，检查是否需要更新后续元素的previous_entry_length字段，其实现函数为`_ziplistCascadeUpdate`，
连锁更新实现逻辑如图4-8所示。

```flow
st=>start: Start
cur=>inputoutput: currentP
calc=>subroutine: 计算长度
next=>inputoutput: 后驱
op=>operation: 当前元素P
currec=>inputoutput: realloc |current
curcopy=>inputoutput: copy
update=>inputoutput: update
updatetail=>inputoutput: updatetail
movep=>inputoutput: moveP
updatenext=>subroutine: updatenext
over=>subroutine: 不需要更新

cond=>condition: rawlen== next.prevrawlen
cond2=>condition: rawlen< next.prevrawlen |current
e=>end
st->cur->calc->next->cond
cond(no)->cond2
cond2(no)->updatenext->e
cond(yes)->over
cond2(yes)->currec
currec->curcopy
curcopy->update->updatetail->movep
movep->cur
```
```
                                     [ 当前元素P]  <----------------------------------------------+
                                           |                                                      |
                                     [    计算当前元素的长度    ]                                 |
                                     [rawlen=zipRawEntryLength()]                                 |
                                           |                                                      |
                                     [   后驱元素  ]                                              |
                                     [next=p+rawlen]                                              |
                                           |                                                      |
                                          / \                        是                           |
                               rawlen == next.prevrawlen ----->   [next不需要更新]                |
                                          \ /                     [    结束      ]                |
                                           |否                                                    |
                                           |                                                      |
                                          / \                        是(next节点必须扩展)         |
                              +----- next.prevrawlensize<rawlensize -----+                        |
                              |           \ /                            |                        |
                              |                                          |                        |
                [      更新next元素   ]                                [重新分配内存]             |
                [previous_entry_length]                                  |                        |
                              |                                        [数据复制]                 |
                              |                                          |                        |
                           [结束]                                      [    更新next元素     ]    |
                                                                       [previous_entry_length]    |
                                                                         |                        |
                                                                       [更新尾节点偏移量zltail]   |
                                                                         |                        |
                                                                       [向后移动指针p]            |
                                                                       [ p=p+len     ]  ----------+
                                         图4-8　连锁更新实现逻辑
```

## 3.4 字典


### 3.4.1 基本概念
字典又称散列表，是用来存储键值（key-value）对的一种数据结构，在很多高级语言中都有实现，如PHP的数组。
但是C语言没有这种数据结构，Redis是K-V型数据库，整个数据库是用字典来存储的，对Redis数据库进行任何增、删、改、查操作，实际就是对字典中的数据进行增、删、改、查操作。

#### 3.4.1.0 字典特征
根据Redis数据库的特点，便可知字典有如下特征。

1. 可以存储海量数据，键值对是映射关系，可以根据键以O(1)的时间复杂度取出或插入关联值。
2. 键值对中键的类型可以是字符串、整型、浮点型等，且键是唯一的。
  例如：执行`set test "hello world"`命令，此时的键test类型为字符串，如test这个键存在数据库中，则为修改操作，否则为插入操作。
3. 键值对中值的类型可为String、Hash、List、Set、SortedSet。

**注意 **
键指的是Redis命令中的key，值为键对应设置的值；例如，set key val命令，键为“key”、值为“val”，key与val合称为键值对。

#### 3.4.1.1 数组
当需要对数组a中元素进行操作时，C语言需通过下标找到其对应的内存地址，然后才能对这块内存进行对应的操作。
例如，读取a[9]的值（见图5-2），C语言实际上会先转换为`*(a+9)`的形式，a[9]与`*(a+9)`这两种形式是等价的，我们对等式两边再取地址，便可得出`&a[9]==a+9`，
也就是说，要得到a[9]的地址，可以通过对数组a的首地址偏移9个元素就行。
由此也可以知道，数组根据下标取值时，是通过头指针和偏移量来实现。

通过前文数组介绍可知，“下标”的含义是数组中第几个元素的意思，只能为整数。
根据第2个特征中键的描述：“键值对中键的类型可以为字符串、整型、浮点型等”，显然不能直接当成下标使用，此时，需要对键做一些特殊处理，处理过程我们称为Hash。

#### 3.4.1.2 Hash函数
作用是把任意长度的输入通过散列算法转换成固定类型、固定长度的散列值，换句话说，Hash函数可以把不同键转换成唯一的整型数据。

散列函数一般拥有如下特征：

1. 相同的输入经Hash计算后得出相同输出；
2. 不同的输入经Hash计算后一般得出不同输出值，但也可能会出现相同输出值。

Redis自带客户端就是使用“times 33”散列函数来计算字符串的Hash值，
Redis服务端的Hash函数使用的是siphash算法，
主要功能与客户端Hash函数类似，其优点是针对有规律的键计算出来的Hash值也具有强随机分布性，但算法较为复杂，
因此，笔者选择了客户端Hash函数作为示例，较为简单，便于读者理解，源码如下：
```c
static unsigned int dictGenHashFunction (const unsigned char *buf, int len) {
    unsigned int hash = 5381;
    while (len--)
        hash = ((hash << 5) + hash) + (*buf++); /* hash * 33 + c */
    return hash;
}
```
`dictGenHashFunction`函数主要作用是，入参是任意长度的字符串，通过Hash计算后返回无符号整型数据。
因此，我们可以通过Hash函数，将任意输入的键转换成整型数据，使其可以当作数组的下标使用。

前文中字典的第2个特征是“键的类型可以为字符串、整型、浮点型等”，而Hash函数只把字符串转换成整型数据，当遇到键的类型为非字符串时该如何处理？
答案很简单，第2个特征中键的类型是客户端感知的，而Redis服务端收到客户端发送过来的键实际都为字符串。

Hash函数可以将任意输入的键转换成整型数据输出，但又引出一个新问题，键的Hash值非常大，直接拿来当数组下标显然不太行，下标值过大会导致存储数据的数组（“data”字段）占用内存过大。
此时我们需要给这个数组的大小设限，
比如Redis的实现，初始化时数组容量为4，已存入数据量将超过总容量时需进行扩容一倍。
因此我们设计的字典数据结构在这就需要添加第2及第3个字段，分别为：

- ①总容量——size字段；
- ②已存入数据量——used字段。
加上这两个字段，字典数据结构示意图可设计为如图5-4所示。
```
+-----------+
| size = 10 |
+-----------+      a[0] a[1]                            a[9]
| ** data   | ---> +---------------------------------------+
+-----------+      | * | * | * | * | * | * | * | * | * | * |
|   used    |      +---------------------------------------+
+-----------+
             图5-4　字典结构示意图（带容量限制）
```
<a id="P5-4"></a>
用Hash值与数组容量取余，会得到一个永远小于数组容量大小的值，此时的值也就恰好可以当作数组下标来使用，我们把取余之后的值称为键在该字典中的索引值，即“索引值\==数组下标值”，拿到“键”的索引值后，我们就知道数组中哪个元素是用来存储键值对中的“值”了。但此方法并不是完美的，还会出现一个问题，Hash冲突。

#### 3.4.1.3 Hash冲突
此时两个不同的键会关联上同一个数组下标，我们称这些键出现了冲突。
为了解决Hash冲突，所以数组中的元素除了应把键值对中的“值”存储外，还应该存储“键”信息和一个next指针，next指针可以把冲突的键值对串成单链表，“键”信息用于判断是否为当前要查找的键。
此时数组中元素的字段也明确了，字典数据结构示意图可设计为如图5-5所示。
```+-----------+
| size = 10 |
+-----------+      a[0] a[1]                            a[9]
| ** data   | ---> +---------------------------------------+
+-----------+      | * | * | * | * | * | * | * | * | * | * |
|   used    |      +---------------------------------------+
+-----------+      /    NULL    NULL                    NULL
                 /                       +---------------+
               +---------------+         |dictEntry(元素)|
               |dictEntry(元素)|         +---------------+
               +---------------+         |*key|*val|*next|
               |*key|*val|*next|         +---------------+
               +---------------+                          \
                          /                                NULL
                        /
                       +---------------+
                       |dictEntry(元素)|
                       +---------------+
                       |*key|*val|*next| ---> NULL
                       +---------------+
                       图5-5　字典结构示意图（整体结构）
```
当根据键去找值时:
第1步： 键通过Hash、取余等操作得到索引值，根据索引值找到对应元素。
第2步： 判断元素中键与查找的键是否相等，相等则读取元素中的值返回，否则判断next指针是否有值，如存在值，则读取next指向元素，回到第2步继续执行，如不存在值，则代表此键在字典中不存在，返回NULL。

### 3.4.2 Redis字典的实现
Redis字典实现依赖的数据结构主要包含了三部分：
字典、Hash表、Hash表节点。
字典中嵌入了两个Hash表，Hash表中的table字段存放着Hash表节点，Hash表节点对应存储的是键值对

#### 3.4.2.1 Hash表

##### 3.4.2.1.1 Hash表结构
Hash表，与<a href="P4-5">3.4.1</a>上节设计的字典结构体类似，在Redis源码中取名为Hash表，其数据结构如下：
```
typedef struct dictht {
    dictEntry **table;                 /*指针数组，用于存储键值对*/
    unsigned long size;                /*table数组的大小*/
    unsigned long sizemask;            /*掩码 = size - 1 */
    unsigned long used;                /*table数组已存元素个数，包含next单链表的数据*/
} dictht;
```
Hash表的结构体整体占用32字节，
其中`table`字段是数组，作用是存储键值对，该数组中的元素指向的是dictEntry的结构体，每个dictEntry里面存有键值对。
`size`表示table数组的总大小。
`used`字段记录着table数组已存键值对个数。
`sizemask`字段用来计算键的索引值，sizemask的值恒等于size–1。

##### 3.4.2.1.2 索引计算
我们知道，索引值是键Hash值与数组总容量取余之后的值，而Redis为提高性能对这个计算进行了优化，具体计算步骤如下。

第1步：
  人为设定Hash表的数组容量初始值为4，随着键值对存储量的增加，就需对Hash表扩容，新扩容的容量大小设定为当前容量大小的一倍，也就是说，Hash表的容量大小只能为4,8,16,32…。
  而sizemask掩码的值就只能为3,7,15,31…，对应的二进制为11,111,1111,11111…，因此掩码值的二进制肯定是每一位都为1。
第2步：
  索引值=Hash值&掩码值，对应Redis源码为：`idx=hash&d->ht[table].sizemask`，其计算结果等同Hash值与Hash表容量取余，而计算机的位运算要比取余运算快很多。
```
+-------------+
|   dictht    |
|+-----------+|
|| size = 4  ||
|+-----------+|        0   1   2   3
|| ** table  || ---> +---------------+
|+-----------+|      | * | * | * | * |
|| sizemask:3||      +---------------+
|+-----------+|      NULL         NULL
||   used :0 ||
|+-----------+|
+-------------+
        图5-6　空Hash表结构示意图
```
#### 3.4.2.2 Hash表节点
Hash表中的元素是用dictEntry结构体来封装的，主要作用是存储键值对，具体结构体如下：
```c
typedef struct dictEntry {
    void *key;                          /*存储键*/
    union {
        void *val;                      /*db.dict中的val*/
        uint64_t u64;
        int64_t s64;                    /*db.expires中存储过期时间*/
        double d;
    } v;                                /*值，是个联合体*/
    struct dictEntry *next;             /*当Hash冲突时，指向冲突的元素，形成单链表*/
} dictEntry;
```

整体占用24字节，key字段存储的是键值对中的键。
v字段是个联合体，存储的是键值对中的值，在不同场景下使用不同字段。

例如，用字典存储整个Redis数据库所有的键值对时，用的是*val字段，可以指向不同类型的值；
再比如，字典被用作记录键的过期时间时，用的是s64字段存储；
当出现了Hash冲突时，next字段用来指向冲突的元素，通过头插法，形成单链表。

#### 3.4.2.3 字典

dictType结构体，里面包含了对该字典操作的函数指针，具体如下:
```c
typedef struct dictType {
    uint64_t (*hashFunction)(const void *key);                             /*该字典对应的Hash函数*/
    void *(*keyDup)(void *privdata, const void *key);                      /*键对应的复制函数*/
    void *(*valDup)(void *privdata, const void *obj);                      /*值对应的复制函数*/
    int (*keyCompare)(void *privdata, const void *key1, const void *key2); /*键的比对函数*/
    void (*keyDestructor)(void *privdata, void *key);                      /*键的销毁函数*/
    void (*valDestructor)(void *privdata, void *obj);                      /*值的销毁函数*/
} dictType;
```
Redis字典实现除了包含前面介绍的两个结构体Hash表及Hash表节点外，还在最外面层封装了一个叫字典的数据结构，
其主要作用是对散列表再进行一层封装，当字典需要进行一些特殊操作时要用到里面的辅助字段。具体结构体如下：
```c
typedef struct dict {
    dictType *type;             /* 该字典对应的特定操作函数*/
    void *privdata;             /* 该字典依赖的数据*/
    dictht ht[2];               /* Hash表，键值对存储在此*/
    long rehashidx;             /* rehash标识。默认值为-1，代表没进行rehash操作；不为-1时，代表正进行rehash操作，存储的值表示Hash表ht[0]的rehash操作进行到了哪个索引值*/
    unsigned long iterators;    /* 当前运行的迭代器数*/
} dict;
```

字典这个结构体整体占用96字节，其中type字段，指向dictType结构体，里面包含了对该字典操作的函数指针，具体如下:

Redis字典这个数据结构，除了主数据库的K-V数据存储外，还有很多其他地方会用到。
例如，Redis的哨兵模式，就用字典存储管理所有的Master节点及Slave节点；
再如，数据库中键值对的值为Hash类型时，存储这个Hash类型的值也是用的字典。
在不同的应用中，字典中的键值对形态都可能不同，而dictType结构体，则是为了实现各种形态的字典而抽象出来的一组操作函数。

- privdata字段，私有数据，配合type字段指向的函数一起使用。
- ht字段，是个大小为2的数组，该数组存储的元素类型为dictht，虽然有两个元素，但一般情况下只会使用ht[0]，只有当该字典扩容、缩容需要进行rehash时，才会用到ht[1]，rehash介绍详见5.3.2节。
- rehashidx字段，用来标记该字典是否在进行rehash，没进行rehash时，值为-1，否则，该值用来表示Hash表ht[0]执行rehash到了哪个元素，并记录该元素的数组下标值。
- iterators字段，用来记录当前运行的安全迭代器数，当有安全迭代器绑定到该字典时，会暂停rehash操作。Redis很多场景下都会用到迭代器，
    例如：执行keys命令会创建一个安全迭代器，此时iterators会加1，命令执行完毕则减1，而执行sort命令时会创建普通迭代器，该字段不会改变，关于迭代器的介绍详见5.4.1节。
```
+------------------------+
|   dict                 |     +-----------+
|| +------------------+  |     |dictEntry* |
|  |  type            |  |     |  +----+   |     +------------------+
|  +------------------+  |     |3 | *  |   |NULL |  dictEntry(元素) |
|  | privdata         |  |     |  |----|   |     |+---------------+ |
|  +------------------+  |     |2 | *  |   | --->||k3 | v3| *next | | ---> NULL
|  |  dictht hy[0]    |  |     |  |----|   |     |+---------------+ |
|  |  +--------------+|  |     |1 | *  |   |NULL +------------------+
|  |  | size = 4     ||  |     |  |----|   |     +------------------+
|  |  +--------------+|  |     |0 | *  |   | --->|  dictEntry(元素) |
|  |  | ** table     ||  | --->|  +----+   |     |+---------------+ |
|  |  +--------------+|  |     +-----------+     ||k3 | v3| *next | |
|  |  | sizemask:3   ||  |                       |+---------------+ | \ hash冲突
|  |  +--------------+|  |                       +------------------+    +------------------+
|  |  |   used :3    ||  |                                               |  dictEntry(元素) |
|  |  +--------------+|  |      +----------+                             |+---------------+ |
|  +------------------+  |      |dictEntry*|                             ||k2 | v2| *next | |--->NULL
|  |  dictht hy[1]    |  |      |  +----+  |                             |+---------------+ |
|  |  +--------------+|  |      |3 | *  |  |                             +------------------+
|  |  | size = 4     ||  |      |  |----|  |
|  |  +--------------+|  |      |2 | *  |  |
|  |  | ** table     ||  |      |  |----|  |
|  |  +--------------+|  |      |1 | *  |  |
|  |  | sizemask:3   ||  |      |  |----|  |
|  |  +--------------+|  |      |0 | *  |  |
|  |  |   used :0    ||  |  --->|  +----+  |
|  |  +--------------+|  |      +----------+
|  +------------------+  |
|  |   rehashidx:-1   |  |
|  +------------------+  |
|  |   iterator : 0   |  |
|  +------------------+  |
+------------------------+
                                       图5-8　Redis字典结构示意图
```

### 3.4.3 字典基本操作
#### 3.4.3.1 字典初始化
原5.3.1
在redis-server启动中，整个数据库会先初始化一个空的字典用于存储整个数据库的键值对。
初始化一个空字典，调用的是`dict.h`文件中的`dictCreate`函数，对应源码为：
```c
/* 创建一个新的Hash表 */
dict *dictCreate(dictType *type,
        void *privDataPtr)
{
    dict *d = zmalloc(sizeof(*d));//96字节
    _dictInit(d,type,privDataPtr);//结构体初始化值
    return d;
}
/* Initialize the hash table */
int _ dictInit (dict *d, dictType *type,
         void *privDataPtr)
{
    _dictReset(&d->ht[0]);
    _dictReset(&d->ht[1]);
    d->type = type;
    d->privdata = privDataPtr;
    d->rehashidx = -1;
    d->iterators = 0;
    return DICT_OK;
}
```
dictCreate函数初始化一个空字典的主要步骤为：
申请空间、调用_dictInit函数，给字典的各个字段赋予初始值。
初始化后，一个字典内存占用情况如图5-9所示。
```
                            +------------------------+
                            |   dict                 |
   0x 7ffff7a0b360     0    |  +------------------+  |
                            |  |  type            |  |
   0x 7ffff7a0b368     8    |  +------------------+  |
                            |  | privdata         |  |
   0x 7ffff7a0b370     16   |  +------------------+  |
                            |  |  dictht hy[0]    |  |
                            |  |  +--------------+|  |
                            |  |  | size = 0     ||  |
                            |  |  +--------------+|  |
                            |  |  | ** table     ||  | ----> NULL
                            |  |  +--------------+|  |
                            |  |  | sizemask:0   ||  |
                            |  |  +--------------+|  |
                            |  |  |   used :0    ||  |
                            |  |  +--------------+|  |
   0x 7ffff7a0b390     48   |  +------------------+  ``|
                            |  |  dictht hy[1]    |  |
                            |  |  +--------------+|  |
                            |  |  | size = 0     ||  |
                            |  |  +--------------+|  |
                            |  |  | ** table     ||  | ----> NULL
                            |  |  +--------------+|  |
                            |  |  | sizemask:0   ||  |
                            |  |  +--------------+|  |
                            |  |  |   used :0    ||  |
                            |  |  +--------------+|  |
   0x 7ffff7a0b3b0     80   |  +------------------+  |
                            |  |   rehashidx:-1   |  |
   0x 7ffff7a0b3b8     88   |  +------------------+  |
                            |  |   iterator : 0   |  |
                            |  +------------------+  |
                            +------------------------+
                            图5-9　Redis空字典内存占用示意图
```
#### 3.4.3.2 添加元素
原5.3.2

##### 3.4.3.2.1 setKey先查找再修改或添加
redis-server启动完后，再启动redis-cli连上Server，执行命令“set k1 v1”：
```shell
[root@4367741a692f src]# ./redis-cli
127.0.0.1:6379> set  k1 v1
```
上述命令是给Server的空数据库添加第一对键值对，Server端收到命令后，最终会执行到`setKey(redisDb*db,robj*key,robj*val)`函数，
前文介绍字典的特性时提到过，每个键必须是唯一的，所以元素添加需要经过这么几步来完成：
先查找该键是否存在，存在则执行修改，否则添加键值对。
而setKey函数的主要逻辑也是如此，其主要流程如下。
```c
/* High level Set operation. This function can be used in order to set
 * a key, whatever it was existing or not, to a new object.
 *
 * 1) The ref count of the value object is incremented.
 * 2) clients WATCHing for the destination key notified.
 * 3) The expire time of the key is reset (the key is made persistent).
 *
 * All the new keys in the database should be craeted via this interface. */
void setKey(redisDb *db, robj *key, robj *val) {
    if (lookupKeyWrite(db,key) == NULL) {
        dbAdd(db,key,val); // 不存在 ，插入
    } else {
        dbOverwrite(db,key,val); // 存在，修改
    }
    incrRefCount(val);
    removeExpire(db,key);
    signalModifiedKey(db,key);
}
```
第1步： 调用`dictFind`函数，查询键是否存在，是则调用`dbOverwrite`函数修改键值对，否则调用dbAdd函数添加元素。
第2步： dbAdd最终调用`dict.h`文件中的`dictAdd`函数插入键值对。

###### 3.4.3.2.1.1 查询键是否存在
> `setKey` 查询 `lookupKeyWrite`
```c
robj *lookupKeyWrite(redisDb *db, robj *key) {
    expireIfNeeded(db,key);
    return lookupKey(db,key,LOOKUP_NONE);
}
```

> `lookupKeyWrite` 调用`dictFind`

```c
/* Low level key lookup API, not actually called directly from commands
 * implementations that should instead rely on lookupKeyRead(),
 * lookupKeyWrite() and lookupKeyReadWithFlags(). */
robj *lookupKey(redisDb *db, robj *key, int flags) {
    dictEntry *de = dictFind(db->dict,key->ptr);
    if (de) {
        robj *val = dictGetVal(de);

        /* Update the access time for the ageing algorithm.
         * Don't do it if we have a saving child, as this will trigger
         * a copy on write madness. */
        if (server.rdb_child_pid == -1 &&
            server.aof_child_pid == -1 &&
            !(flags & LOOKUP_NOTOUCH))
        {
            if (server.maxmemory_policy & MAXMEMORY_FLAG_LFU) {
                updateLFU(val);
            } else {
                val->lru = LRU_CLOCK();
            }
        }
        return val;
    } else {
        return NULL;
    }
}
```

```c
// dictFind 查询是否存在
dictEntry *dictFind(dict *d, const void *key)
{
    dictEntry *he;
    uint64_t h, idx, table;

    if (d->ht[0].used + d->ht[1].used == 0) return NULL; /* dict is empty */
    if (dictIsRehashing(d)) _dictRehashStep(d);
    h = dictHashKey(d, key);
    for (table = 0; table <= 1; table++) {
        idx = h & d->ht[table].sizemask;
        he = d->ht[table].table[idx];
        while(he) {
            if (key==he->key || dictCompareKeys(d, key, he->key))
                return he;
            he = he->next;
        }
        if (!dictIsRehashing(d)) return NULL;
    }
    return NULL;
}
```
###### 3.4.3.2.1.2 存在进行插入调用 dbOverwrite
```c
/* Overwrite an existing key with a new value. Incrementing the reference
 * count of the new value is up to the caller.
 * This function does not modify the expire time of the existing key.
 *
 * The program is aborted if the key was not already present. */
void dbOverwrite(redisDb *db, robj *key, robj *val) {
    dictEntry *de = dictFind(db->dict,key->ptr);

    serverAssertWithInfo(NULL,key,de != NULL);
    dictEntry auxentry = *de;
    robj *old = dictGetVal(de);
    if (server.maxmemory_policy & MAXMEMORY_FLAG_LFU) {
        val->lru = old->lru;
    }
    dictSetVal(db->dict, de, val);

    if (server.lazyfree_lazy_server_del) {
        freeObjAsync(old);
        dictSetVal(db->dict, &auxentry, NULL);
    }

    dictFreeVal(db->dict, &auxentry);
}
```
###### 3.4.3.2.1.3 不存在进行插入调用 dbAdd - dictAdd - dictAddRaw - _dictKeyIndex
`dbAdd(db,key,val); `// 不存在 ，进行插入
```c
/* Add the key to the DB. It's up to the caller to increment the reference
 * counter of the value if needed.
 *
 * The program is aborted if the key already exists. */
void dbAdd(redisDb *db, robj *key, robj *val) {
    sds copy = sdsdup(key->ptr);
    int retval = dictAdd(db->dict, copy, val);

    serverAssertWithInfo(NULL,key,retval == DICT_OK);
    if (val->type == OBJ_LIST ||
        val->type == OBJ_ZSET)
        signalKeyAsReady(db, key);
    if (server.cluster_enabled) slotToKeyAdd(key);
}
```
继续查看dictAdd函数是如何插入键值对的，其源码如下：
```c
int dictAdd(dict *d, void *key, void *val){  /*调用前会查找key存在与否，不存在则调用dictAdd 函数*/
    dictEntry *entry = dictAddRaw(d,key,NULL); /*添加键，字典中键已存在则返回NULL，否则添加键至新节点中，返回新节点*/
    if (!entry) return DICT_ERR;               /*键存在则返回错误*/
    dictSetVal(d, entry, val);                 /*设置值*/
    return DICT_OK;
}
```
`dictAdd`函数主要作用是，添加键值对，执行步骤如下。

1. 调用dictAddRaw函数，添加键，字典中键已存在则返回NULL，否则添加键至Hash表中，并返回新加的Hash节点。
2. 给返回的新节点设置值，即更新其val字段。
我们再看下dictAddRaw函数如何做到添加键与查找键，其源码如下：
```c
dictEntry *dictAddRaw(dict *d, void *key, dictEntry **existing)/*入参字典、键、Hash表节点地址*/
{
    if (dictIsRehashing(d)) _dictRehashStep(d);  /*该字典是否在进行rehash操作中,是则执行一次rehash*/
    if ((index = _dictKeyIndex(d, key, dictHashKey(d,key), existing)) == -1)
        return NULL;
        /*查找键，找到则直接返回-1, 并把老节点存入existing字段，否则把新节点的索引值返回。如果遇到Hash表容量不足，则进行扩容*/
    ht = dictIsRehashing(d) ? &d->ht[1] : &d->ht[0]; /*是否进行rehash操作中,是则插入至散列表ht[1]中，否则插入散列表ht[0] */
    /*申请新节点内存，插入散列表中，给新节点存入键信息*/
    entry = zmalloc(sizeof(*entry));
    entry->next = ht->table[index];
    ht->table[index] = entry;
    ht->used++;
    dictSetKey(d, entry, key);
    return entry;
}
```
`dictAddRaw`函数主要作用是添加或查找键，添加成功返回新节点，查找成功返回NULL并把老节点存入existing字段。
该函数中比较核心的是调用`_dictKeyIndex`函数，作用是得到键的索引值，索引值获取与前文介绍的函数类似，主要有这么两步：

```
dictHashKey(d,key)                  //第1步：调用该字典的Hash函数得到键的Hash值
idx = hash & d->ht[table].sizemask; //第2步：用键的Hash值与字典掩码取与，得到索引值
```

```c
/* Returns the index of a free slot that can be populated with
 * a hash entry for the given 'key'.
 * If the key already exists, -1 is returned
 * and the optional output parameter may be filled.
 *
 * Note that if we are in the process of rehashing the hash table, the
 * index is always returned in the context of the second (new) hash table. */
static long _dictKeyIndex(dict *d, const void *key, uint64_t hash, dictEntry **existing)
{
    unsigned long idx, table;
    dictEntry *he;
    if (existing) *existing = NULL;

    /* Expand the hash table if needed */
    if (_dictExpandIfNeeded(d) == DICT_ERR)
        return -1;
    for (table = 0; table <= 1; table++) {
        idx = hash & d->ht[table].sizemask;
        /* Search if this slot does not already contain the given key */
        he = d->ht[table].table[idx];
        while(he) {
            if (key==he->key || dictCompareKeys(d, key, he->key)) {
                if (existing) *existing = he;
                return -1;
            }
            he = he->next;
        }
        if (!dictIsRehashing(d)) break;
    }
    return idx;
}

```
`dictAddRaw`函数拿到键的索引值后则可直接定位“键值对”要存入的位置，新创建一个节点存入即可。
执行完添加键值对操作后，字典对应的内存占用结构示意图，如图5-10所示。
```
                            +------------------------+
                            |   dict                 |      +-----------+
   0x 7ffff7a0b360     0    |  +------------------+  |      | dictEntry*|
                            |  |  type            |  |      |  +----+   |        +------------------+
   0x 7ffff7a0b368     8    |  +------------------+  |      |3 | *  |   |-->NULL |  dictEntry(元素) |
                            |  | privdata         |  |      |  |----|   |        |+---------------+ |
   0x 7ffff7a0b370     16   |  +------------------+  |      |2 | *  |   |        ||    key:k1     | |
                            |  |  dictht hy[0]    |  |      |  |----|   |        |+---------------+ |
                            |  |  +--------------+|  |      |1 | *  |   |-->NULL ||  v.val:v1     | |
                            |  |  | size = 4     ||  |      |  |----|   |        |+---------------+ |
                            |  |  +--------------+|  |      |0 | *  |   |-->NULL ||    *next      | | -->NULL
                            |  |  | ** table     ||  | ---->|  +----+   |        |+---------------+ |
                            |  |  +--------------+|  |      +-----------+        +------------------+
                            |  |  | sizemask:3   ||  |
                            |  |  +--------------+|  |                       说明: dictEntry 中key与v.val实际为指针
                            |  |  |   used :1    ||  |                             为展示方便，故将值直接写入dictEntry中
                            |  |  +--------------+|  |
   0x 7ffff7a0b390     48   |  +------------------+  |
                            |  |  dictht hy[1]    |  |
                            |  |  +--------------+|  |
                            |  |  | size = 0     ||  |
                            |  |  +--------------+|  |
                            |  |  | ** table     ||  | ----> NULL
                            |  |  +--------------+|  |
                            |  |  | sizemask:0   ||  |
                            |  |  +--------------+|  |
                            |  |  |   used :0    ||  |
                            |  |  +--------------+|  |
   0x 7ffff7a0b3b0     80   |  +------------------+  |
                            |  |   rehashidx:-1   |  |
   0x 7ffff7a0b3b8     88   |  +------------------+  |
                            |  |   iterator : 0   |  |
                            |  +------------------+  |
                            +------------------------+
                            图5-10　字典添加一个元素后（结构示意图）
```
##### 3.4.3.2.2 字典扩容
随着Redis数据库添加操作逐步进行，存储键值对的字典会出现容量不足，达到上限，此时就需要对字典的Hash表进行扩容，
扩容对应的源码是`dict.h`文件中的`dictExpand`函数，对应源码如下:
```c
int dictExpand(dict *d, unsigned long size){//传入size = d->ht[0].used*2
    dictht n; /* the new hash table */
    unsigned long realsize = _dictNextPower(size); /*重新计算扩容后的值，必须为2的N次方幂*/
    /* Allocate the new hash table and initialize all pointers to NULL */
    n.size = realsize;
    n.sizemask = realsize-1;
    n.table = zcalloc(realsize*sizeof(dictEntry*));
    n.used = 0;
    /* Prepare a second hash table for incremental rehashing */
    d->ht[1] = n;        /*扩容后的新内存放入ht[1]中*/
    d->rehashidx = 0;        /*非默认的-1,表示需进行rehash*/
    return DICT_OK;
}

```
扩容主要流程为：

- ①申请一块新内存，初次申请时默认容量大小为4个dictEntry；
  非初次申请时，申请内存的大小则为当前Hash表容量的一倍。
- ②把新申请的内存地址赋值给ht[1]，并把字典的rehashidx标识由-1改为0，表示之后需要进行rehash操作。

此时字典的内存结构示意图为图5-11所示。
```
                           +------------------------+
                            |   dict                 |      +-----------+
   0x 7ffff7a0b360     0    |  +------------------+  |      | dictEntry*|
                            |  |  type            |  |      |  +----+   |             +------------------+
   0x 7ffff7a0b368     8    |  +------------------+  |      |3 | *  | --|-->dictEntry |  dictEntry(元素) |
                            |  | privdata         |  |      |  |----|   |             |+---------------+ |
   0x 7ffff7a0b370     16   |  +------------------+  |      |2 | *  | --|-----------> ||    key:k1     | |
                            |  |  dictht hy[0]    |  |      |  |----|   |             |+---------------+ |
                            |  |  +--------------+|  |      |1 | *  | --|-->dictEntry ||  v.val:v1     | |
                            |  |  | size = 4     ||  |      |  |----|   |             |+---------------+ |
                            |  |  +--------------+|  |      |0 | *  | --|-->dictEntry ||    *next      | | -->NULL
                            |  |  | ** table     ||  | ---->|  +----+   |             |+---------------+ |
                            |  |  +--------------+|  |      +-----------+             +------------------+
                            |  |  | sizemask:3   ||  |
                            |  |  +--------------+|  |      +-----------+
                            |  |  |   used :4    ||  |      | dictEntry*|
                            |  |  +--------------+|  |      |  +----+   |
   0x 7ffff7a0b390     48   |  +------------------+  |      |7 | *  | --|-->NULL
                            |  |  dictht hy[1]    |  |      |  |----|   |
                            |  |  +--------------+|  |      |6 | *  | --|-->NULL
                            |  |  | size = 8     ||  |*     |  |----|   |
                            |  |  +--------------+|  |      |5 | *  | --|-->NULL
                            |  |  | ** table     ||  | *    |  |----|   |
                            |  |  +--------------+|  |      |4 | *  | --|-->NULL
                            |  |  | sizemask:7   ||  |  *   |  +----+   |
                            |  |  +--------------+|  |      |3 | *  | --|-->NULL
                            |  |  |   used :0    ||  |   *  |  |----|   |
                            |  |  +--------------+|  |      |2 | *  | --|-->NULL
   0x 7ffff7a0b3b0     80   |  +------------------+  |    * |  |----|   |
                            |  |   rehashidx: 0   |  |      |1 | *  | --|-->NULL
   0x 7ffff7a0b3b8     88   |  +------------------+  |     *|  |----|   |
                            |  |   iterator : 0   |  |      |0 | *  | --|-->NULL
                            |  +------------------+  |      |  +----+   |
                            +------------------------+      +-----------+
                            图5-11　扩容后结构示意图
```
扩容后，字典容量及掩码值会发生改变，同一个键与掩码经位运算后得到的索引值就会发生改变，从而导致根据键查找不到值的情况。
解决这个问题的方法是，新扩容的内存放到一个全新的Hash表中（ht[1]），并给字典打上在进行rehash操作中的标识（即rehashidx!=-1）。
此后，新添加的键值对都往新的Hash表中存储；而修改、删除、查找操作需要在ht[0]、ht[1]中进行检查，然后再决定去对哪个Hash表操作。
除此之外，还需要把老Hash表（ht[0]）中的数据重新计算索引值后全部迁移插入到新的Hash表(ht[1])中，此迁移过程称作rehash，
我们下面讲解rehash的实现。

##### 3.4.3.2.3 渐进式rehash
rehash除了扩容时会触发，缩容时也会触发。Redis整个rehash的实现，主要分为如下几步完成。

1. 给Hash表ht[1]申请足够的空间；扩容时空间大小为当前容量*2，即`d->ht[0].used*2`；当使用量不到总空间10%时，则进行缩容。
    缩容时空间大小则为能恰好包含`d->ht[0].used`个节点的`2^N`次方幂整数，并把字典中字段rehashidx标识为0。
2. 进行rehash操作调用的是`dictRehash`函数，重新计算ht[0]中每个键的Hash值与索引值（重新计算就叫rehash），依次添加到新的Hash表ht[1]，并把老Hash表中该键值对删除。
    把字典中字段rehashidx字段修改为Hash表ht[0]中正在进行rehash操作节点的索引值。
3. rehash操作后，清空ht[0]，然后对调一下ht[1]与ht[0]的值，并把字典中rehashidx字段标识为-1。

Redis优化的思想很巧妙，利用分而治之的思想了进行rehash操作，

执行插入、删除、查找、修改等操作前，都先判断当前字典rehash操作是否在进行中，
进行中则调用`dictRehashStep`函数进行rehash操作（每次只对1个节点进行rehash操作，共执行1次）。
除这些操作之外，当服务空闲时，如果当前字典也需要进行rehsh操作，则会调用`incrementallyRehash`函数进行批量rehash操作（每次对100个节点进行rehash操作，共执行1毫秒）。
在经历N次rehash操作后，整个ht[0]的数据都会迁移到ht[1]中，这样做的好处就把是本应集中处理的时间分散到了上百万、千万、亿次操作中，所以其耗时可忽略不计。

图5-10经过渐进式rehash后的结构示意图如图5-12所示
```
                            +------------------------+
                            |   dict                 |       +-----------+
   0x 7ffff7a0b360     0    |  +------------------+  |       | dictEntry*|
                            |  |  type            |  |       |  +----+   |             +------------------+
   0x 7ffff7a0b368     8    |  +------------------+  |       |7 | *  | --|-->dictEntry |  dictEntry(元素) |
                            |  | privdata         |  |       |  |----|   |             |+---------------+ |
   0x 7ffff7a0b370     16   |  +------------------+  |       |6 | *  | --|-----------> ||    key:k1     | |
                            |  |  dictht hy[0]    |  |       |  |----|   |             |+---------------+ |
                            |  |  +--------------+|  |       |5 | *  | --|-->          ||  v.val:v1     | |
                            |  |  | size = 8     ||  |       |  |----|   |             |+---------------+ |
                            |  |  +--------------+|  |       |4 | *  | --|-->          ||    *next      | | -->NULL
                            |  |  | ** table     ||  |*      |  +----+   |             |+---------------+ |
                            |  |  +--------------+|  | *     |3 | *  | --|-->          +------------------+
                            |  |  | sizemask:7   ||  |  *    |  |----|   |
                            |  |  +--------------+|  |   *   |2 | *  | --|-->
                            |  |  |   used :5    ||  |    *  |  |----|   |
                            |  |  +--------------+|  |     * |1 | *  | --|--> dictEntry
   0x 7ffff7a0b390     48   |  +------------------+  |      *|  |----|   |
                            |  |  dictht hy[1]    |  |       |0 | *  | --|--> dictEntry
                            |  |  +--------------+|  |       |  +----+   |
                            |  |  | size = 0     ||  |       +-----------+
                            |  |  +--------------+|  |
                            |  |  | ** table     ||  |
                            |  |  +--------------+|  |
                            |  |  | sizemask:0   ||  |
                            |  |  +--------------+|  |
                            |  |  |   used :0    ||  |
                            |  |  +--------------+|  |
   0x 7ffff7a0b3b0     80   |  +------------------+  |
                            |  |   rehashidx:-1   |  |
   0x 7ffff7a0b3b8     88   |  +------------------+  |
                            |  |   iterator : 0   |  |
                            |  +------------------+  |
                            +------------------------+
                            图5-12　渐进式rehash后结构示意图
```
#### 3.4.3.3 查找元素
原5.3.3
```redis
127.0.0.1:6379> get  k1
"v1"
```
Server收到get命令后，最终查找键值对会执行到`dict.h`文件中的`dictFind`函数，源码如下：

```c
dictFind(dict *d, const void *key){
    h = dictHashKey(d, key);              //得到键的Hash值
    for (table = 0; table <= 1; table++) {//遍历查找Hash表 ht[0]与ht[1]
        idx = h & d->ht[table].sizemask;  //根据Hash值获取到对应的索引值
        he = d->ht[table].table[idx];
        while(he) {                         //如果存在值则遍历该值中的单链表
            if (key==he->key || dictCompareKeys(d, key, he->key))
                return he;                  //找到与键相等的值,返回该节点
            he = he->next;
        }
        if (!dictIsRehashing(d)) return NULL;//如果未进行rehash操作，则只读取ht[0]
    }
    return NULL;
}
```

查找键的源码，整个过程比较简单，主要分如下几个步骤。

1. 根据键调用Hash函数取得其Hash值。
2. 根据Hash值取到索引值。
3. 遍历字典的两个Hash表，读取索引对应的元素。
4. 遍历该元素单链表，如找到了与自身键匹配的键，则返回该元素。
5. 找不到则返回NULL。

#### 3.4.3.4 修改元素

原5.3.4
127.0.0.1:6379> set  k1 v1_update
OK
Server收到set命令后，会查询键是否已经在数据库中存在，存在则最终会执行`db.c`文件中的`dbOverwrite`函数，其源码如下：
```c
void dbOverwrite(redisDb *db, robj *key, robj *val) {
    dictEntry *de = dictFind(db->dict,key->ptr); //查找键存在与否，返回存在的节点
    serverAssertWithInfo(NULL,key,de != NULL);   //不存在则中断执行
    dictEntry auxentry = *de;
    robj *old = dictGetVal(de);                  //获取老节点的val字段值
    dictSetVal(db->dict, de, val);               //给节点设置新的值
        dictFreeVal(db->dict, &auxentry);        //释放节点中旧val内存
}
```
修改键的源码，虽然没有调用dict.h中的方法去修改字典中元素，但修改过程基本类似，Redis修改键值对，整个过程主要分如下几个步骤：

1. 调用dictFind查找键是否存在；
2. 不存在则中断执行；
3. 修改节点键值对中的值为新值；
4. 释放旧值内存。
#### 3.4.3.5 删除元素
原5.3.5
Server收到del命令后，最终删除键值对会执行`dict.h`文件中的`dictDelete`函数，其主要的执行过程为：
1. 查找该键是否存在于该字典中；
2. 存在则把该节点从单链表中剔除；
3. 释放该节点对应键占用的内存、值占用的内存，以及本身占用的内存；
4. 给对应的Hash表的used字典减1操作。

当字典中数据经过一系列操作后，使用量不到总空间小于10%时，就会进行缩容操作，将Redis数据库占用内存保持在合理的范围内，不浪费内存。
字典缩容的核心函数有两个：

```c
	void tryResizeHashTables(int dbid) {
	    if (htNeedsResize(server.db[dbid].dict))  //判断是否需要缩容：used/size<10 %
	        dictResize(server.db[dbid].dict);     //执行缩容操作
	}
	int dictResize (dict *d){                     //缩容函数
	    int minimal;
	    minimal = d->ht[0].used;
	    if (minimal < DICT_HT_INITIAL_SIZE)       //容量最小值为4
	        minimal = DICT_HT_INITIAL_SIZE;
	    return dictExpand (d, minimal);           //调用扩容函数，实质进行的是缩容
	}
```
整个缩容的步骤大致为：
判断当前的容量是否达到最低阈值，即used/size小于10%，达到了则调用dictResize函数进行缩容，缩容后的函数容量实质为used的最小2^N 整数。
缩容操作和扩容操作实质差不多，最终调用的都是`dictExpand`函数，之后的操作与扩容一致，不再重复讲解。

### 3.4.4 字典的遍历
遍历数据库的原则为：
①. 不重复出现数据；
②. 不遗漏任何数据。

熟悉Redis命令的读者应该知道，遍历Redis整个数据库主要有两种方式：

- 全遍历 （例如keys命令）
  * 全遍历：一次命令执行就遍历完整个数据库。
- 间断遍历 （hscan命令）
  * 间断遍历：每次命令执行只取部分数据，分多次遍历。

#### 3.4.4.1 迭代器遍历
迭代器——可在容器（容器可为字典、链表等数据结构）上遍访的接口，设计人员无须关心容器的内容，调用迭代器固定的接口就可遍历数据，在很多高级语言中都有实现。

字典迭代器主要用于迭代字典这个数据结构中的数据，既然是迭代字典中的数据，必然会出现一个问题:
迭代过程中，如果发生了数据增删，则可能导致字典触发rehash操作，或迭代开始时字典正在进行rehash操作，从而导致一条数据可能多次遍历到。
那Redis如何解决这个问题呢？带着这个疑问，我们接下来一起看下迭代器的实现。

Redis源码中迭代器实现的基本数据结构如下：
```c
typedef struct dictIterator {
    dict *d;                     //迭代的字典
    int index;                   //当前迭代到Hash表中哪个索引值
    int table, safe;             //table用于表示当前正在迭代的Hash表,即ht[0]与ht[1]，safe用于表示当前创建的是否为安全迭代器
    dictEntry *entry, *nextEntry;//当前节点，下一个节点
    long long fingerprint;       //字典的指纹，当字典未发生改变时，该值不变，发生改变时则值也随着改变
} dictIterator;
```
整个数据结构占用了48字节，
其中d字段指向需要迭代的字典；

- index字段代表当前读取到Hash表中哪个索引值；
- table字段表示当前正在迭代的Hash表（即ht[0]与ht[1]中的0和1）；
- safe字段表示当前创建的迭代器是否为安全模式；
- entry字段表示正在读取的节点数据；
- nextEntry字段表示entry节点中的next字段所指向的数据。
- fingerprint字段是一个64位的整数，表示在给定时间内字典的状态。
  * 在这里称其为字典的指纹，因为该字段的值为字典（dict结构体）中所有字段值组合在一起生成的Hash值，
  * 所以当字典中数据发生任何变化时，其值都会不同，生成算法不做过多解读，读者可参见源码dict.c文件中的`dictFingerprint`函数。


Redis也提供了迭代相关的API函数，主要为：
```c
dictIterator *dictGetIterator(dict *d);                /*初始化迭代器*/
dictIterator *dictGetSafeIterator(dict *d);            /*初始化安全的迭代器*/
dictEntry *dictNext(dictIterator *iter);               /*通过迭代器获取下一个节点*/
void dictReleaseIterator(dictIterator *iter);          /*释放迭代器*/
```

Redis如何解决增删数据的同时不出现读取数据重复的问题。
Redis为单进程单线程模式，不存在两个命令同时执行的情况，因此只有当执行的命令在遍历的同时删除了数据，才会触发前面的问题。

我们把迭代器遍历数据分为两类：

1. 普通迭代器，只遍历数据；
2. 安全迭代器，遍历的同时删除数据。

##### 3.4.4.1.1 普通迭代器``

普通迭代器迭代字典中数据时，会对迭代器中`fingerprint`字段的值作严格的校验，来保证迭代过程中字典结构不发生任何变化，确保读取出的数据不出现重复。

当Redis执行部分命令时会使用普通迭代器迭代字典数据，
例如sort命令。sort命令主要作用是对给定列表、集合、有序集合的元素进行排序，如果给定的是有序集合，其成员名存储用的是字典，分值存储用的是跳跃表，则执行sort命令读取数据的时候会用到迭代器来遍历整个字典。

普通迭代器迭代数据的过程比较简单，主要分为如下几个步骤。

1. 调用`dictGetIterator`函数初始化一个普通迭代器，此时会把`iter->safe`值置为0，表示初始化的迭代器为普通迭代器，初始化后的结构示意图如图5-13所示。
2. 循环调用`dictNext`函数依次遍历字典中Hash表的节点，首次遍历时会通过`dictFingerprint`函数拿到当前字典的指纹值，此时结构示意图如图5-14所示。


图5-14　迭代一次后迭代器结构示意图

** 注意 **　`entry`与`nextEntry`两个指针分别指向Hash冲突后的两个父子节点。
如果在安全模式下，删除了`entry`节点，`nextEntry`字段可以保证后续迭代数据不丢失。

3. 当调用dictNext函数遍历完字典Hash表中节点数据后，释放迭代器时会继续调用dictFingerprint函数计算字典的指纹值，并与首次拿到的指纹值比较，不相等则输出异常"`===ASSERTION FAILED==="，且退出程序执行。

普通迭代器通过步骤1、步骤3的指纹值对比，来限制整个迭代过程中只能进行迭代操作，即迭代过程中字典数据的修改、添加、删除、查找等操作都不能进行，只能调用dictNext函数迭代整个字典，否则就报异常，由此来保证迭代器取出数据的准确性。

# 4.面试
[46道史上最全Redis面试题](https://blog.csdn.net/jjc4261/article/details/130400863)
[21道 Redis 最常问面试题](https://blog.csdn.net/w915209092/article/details/126035419)

## **Redis的数据结构有哪些，分别适用于什么场景？**

Redis支持多种数据结构，包括字符串、哈希、列表、集合和有序集合。

- 字符串（String）：适用于存储单个的值，可以存储字符串、整数和浮点数等类型的数据。
- 哈希（Hash）：适用于存储对象，可以将一个对象的多个字段存储在一个哈希结构中，支持增量更新。
- 列表（List）：适用于存储多个有序的值，可在列表的两端执行插入和删除操作。
- 集合（Set）：适用于存储多个无序、唯一的值，支持并集、交集、差集等操作。
- 有序集合（Sorted Set）：适用于存储多个有序的值，每个值都关联有一个分数，支持按照分数范围查找和排序。

## 什么是缓存穿透？如何避免？什么是缓存雪崩？何如避免？
**缓存穿透**
一般的缓存系统，都是按照 key 去缓存查询，如果不存在对应的 value，就应该去后端系统查找（比如DB）。一些恶意的请求会故意查询不存在的 key,请求量很大，就会对后端系统造成很大的压力。这就叫做缓存穿透。
**如何避免？**
1：对查询结果为空的情况也进行缓存，缓存时间设置短一点，或者该 key 对应的数据 insert 了之后清理缓存。
2：对一定不存在的 key 进行过滤。可以把所有的可能存在的 key 放到一个大的 Bitmap 中，查询时通过该 bitmap 过滤。

**缓存雪崩**
当缓存服务器重启或者大量缓存集中在某一个时间段失效，这样在失效的时候，会给后端系统带来很大压力。导致系统崩溃。
**如何避免？**
1：在缓存失效后，通过加锁或者队列来控制读数据库写缓存的线程数量。比如对某个 key 只允许一个线程查询数据和写缓存，其他线程等待。
2：做二级缓存，A1 为原始缓存，A2 为拷贝缓存，A1 失效时，可以访问 A2，A1 缓存失效时间设置为短期，A2 设置为长期
3：不同的 key，设置不同的过期时间，让缓存失效的时间点尽量均匀

**假如Redis里面有1亿个key，其中有10w个key是以某个固定的已知的前缀开头的，如果将它们全部找出来？**
使用keys指令可以扫出指定模式的key列表。

对方接着追问：如果这个redis正在给线上的业务提供服务，那使用keys指令会有什么问题？

这个时候你要回答redis关键的一个特性：redis的单线程的。keys指令会导致线程阻塞一段时间，线上服务会停顿，直到指令执行完毕，服务才能恢复。这个时候可以使用scan指令，scan指令可以无阻塞的提取出指定模式的key列表，但是会有一定的重复概率，在客户端做一次去重就可以了，但是整体所花费的时间会比直接用keys指令长。

## **Redis如何做持久化的？**
bgsave做镜像全量持久化，aof做增量持久化。因为bgsave会耗费较长时间，不够实时，在停机的时候会导致大量丢失数据，所以需要aof来配合使用。在redis实例重启时，会使用bgsave持久化文件重新构建内存，再使用aof重放近期的操作指令来实现完整恢复重启之前的状态。

对方追问那如果突然机器掉电会怎样？取决于aof日志sync属性的配置，如果不要求性能，在每条写指令时都sync一下磁盘，就不会丢失数据。但是在高性能的要求下每次都sync是不现实的，一般都使用定时sync，比如1s1次，这个时候最多就会丢失1s的数据。

对方追问bgsave的原理是什么？你给出两个词汇就可以了，fork和cow。fork是指redis通过创建子进程来进行bgsave操作，cow指的是copy on write，子进程创建后，父子进程共享数据段，父进程继续提供读写服务，写脏的页面数据会逐渐和子进程分离开来。

## **Redis的主从复制原理是什么？**

Redis的主从复制是一种常用的数据备份和负载均衡方案。其中，主节点（Master）是写入和读取数据的节点，从节点（Slave）是只读节点，将主节点上的数据复制到自己的内存中，实现数据备份和负载均衡。

主从复制的原理如下：

- 从节点连接主节点，并发送SYNC命令，请求复制主节点的数据。
- 主节点在接收到SYNC命令后，进行全量复制或增量复制，将数据发送给从节点。
- 从节点接收到主节点的数据后，将数据保存到自己的内存中。
- 从节点定期向主节点发送PING命令，检查主节点是否可用。如果主节点不可用，从节点会重新连接其他可用的主节点，并进行数据复制。

在主节点的配置文件中，添加以下配置项：

```text
slaveof no one  # 表示当前实例为主节点
```

在从节点的配置文件中，添加以下配置项：

```text
slaveof <master-ip> <master-port>  # 指定主节点的IP地址和端口号
```

## **是否使用过Redis集群，集群的原理是什么？**

Redis Sentinal着眼于高可用，在master宕机时会自动将slave提升为master，继续提供服务。
Redis Cluster着眼于扩展性，在单个redis内存不足时，使用Cluster进行分片存储。

Redis 哨兵（Sentinel）和群组（Cluster）是两种不同的高可用性和可扩展性解决方案，它们各自解决了在分布式环境中运行 Redis 时遇到的不同问题。

### Redis Sentinel (哨兵)

Redis Sentinel 是一个用于监控 Redis 实例的系统，并且可以在主节点发生故障时自动进行故障转移。它能够确保即使主服务器出现故障，服务也可以继续通过将一个从服务器提升为主服务器来提供。

**主要功能：**
- 监控：Sentinel 会定期检查你的主服务器和从服务器是否正常运行。
- 通知：当被监视的某个 Redis 实例出现问题时，Sentinel 可以发送通知给管理员或者其他客户端。
- 自动故障转移：如果主服务器宕机，Sentinel 会选出一个从服务器并将其升级为新的主服务器，同时更新其他从服务器的配置，使它们指向新的主服务器。
- 配置提供者：客户端可以从 Sentinel 获取当前主服务器的地址信息。

**设置步骤：**
1. 安装 Redis 并确保你有至少一个主服务器和一个或多个从服务器。
2. 配置 Sentinel 的配置文件 `sentinel.conf`，指定要监视的主服务器以及其它参数如 quorum 等。
3. 启动 Sentinel 进程，通常需要启动多个 Sentinel 实例以形成一个集群，从而实现高可用性。
4. 配置客户端使用 Sentinel 来获取主服务器的信息。

### Redis Cluster (群组)

Redis Cluster 提供了一种方法来运行 Redis 的分布式版本，其中数据可以自动分布在多个节点上。这种分布允许你在单个 Redis 节点无法存储所有数据的情况下进行水平扩展。

**主要特点：**
- 数据分片：数据集被分割成多个片段，每个片段可以由不同的 Redis 节点管理。
- 自动故障检测和恢复：当某个节点不可用时，集群会尝试将该节点上的数据复制到其他节点。
- 智能客户端：客户端可以直接与任何节点通信，并且知道如何根据键将请求路由到正确的节点。

**设置步骤：**
1. 准备好多个 Redis 实例，每个实例都将作为集群中的一个节点。
2. 使用 `redis-cli` 工具创建集群，或者手动编辑每个节点的配置文件并启动它们。
3. 执行 `redis-cli --cluster create` 命令加上各个节点的 IP 地址和端口来初始化集群。
4. 配置客户端以支持集群模式，这样客户端就可以正确地向集群发送命令了。

为了获得更详细的指导，你应该参考 Redis 的官方文档，因为这些过程可能会随着版本更新而有所变化。此外，实际部署前应该在测试环境中充分验证设置。