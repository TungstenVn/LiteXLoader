## 📚 NbtList - 列表类型

一个`NbtList`代表一个列表，里面储存了一列 NBT 对象，类似于列表 / 数组这样的数据结构。  
对于某个一个`NbtList`类型的对象`list`，有如下这些接口

#### 获取列表长度

`list.getSize()`

- 返回值：此列表的长度
- 返回值类型：`Integer`

<br>

#### 获取某个下标位置储存的数据类型

`nbt.getTypeOf(index)`

- 参数：
  - index : `Integer`  
    要查询的目标下标
- 返回值：此坐标处储存的NBT的数据类型
- 返回值类型：`Enum`

可能的返回值有：`NBT.End` `NBT.Byte` `NBT.Short` `NBT.Int` `NBT.Long`   
`NBT.Float` `NBT.Double` `NBT.ByteArray` `NBT.String`  
`NBT.List` `NBT.Compound`

<br>

#### 设置某个下标位置的具体数据（方便函数）

`list.setEnd(index)`  
`list.setByte(index,data)`  
`list.setShort(index,data)`  
`list.setInt(index,data)`  
`list.setLong(index,data)`  
`list.setFloat(index,data)`  
`list.setDouble(index,data)`  
`list.setString(index,data)`    

- 参数：
  - index : `Integer`  
    要操作的目标下标
  - data: `上述类型`  
    要写入的具体数据  
    写入数据类型必须和下标位置储存的数据类型一致，且下标不能超出有效下标的最大值
- 返回值：写入完毕的NBT列表（便于连锁set）
- 返回值类型：`NbtList`

<br>

#### 设置某个下标位置的NBT对象

`list.setTag(index,tag)`

- 参数：
  - index : `Integer`  
    要操作的目标下标
  - tag: `NbtValue` 或 `NbtList` 或 `NbtCompound`  
    要写入的 NBT 对象（它承载着具体的NBT数据）  
    写入对象的数据类型必须和下标位置储存的数据类型一致，且下标不能超出有效下标的最大值
- 返回值：写入完毕的NBT列表（便于连锁set）
- 返回值类型：`NbtList`

<br>

#### 读取某个下标位置的具体数据（方便函数）

`list.getData(index)`  

- 参数：
  - index : `Integer`  
    要操作的目标下标
- 返回值：指定位置储存的具体数据
- 返回值类型：`任意类型`，以对象储存的数据类型为准
  - 如果目标位置储存的是`List`类型 NBT，将返回一个`NbtList`对象；如果目标位置储存的是`Compound`类型 NBT，将返回一个`NbtCompound`对象

<br>

#### 读取某个下标位置的NBT对象

`list.getTag(index)`

- 参数：
  - index : `Integer`  
    要操作的目标下标
- 返回值：下标位置的NBT对象
- 返回值类型：`NbtValue` 或 `NbtList` 或 `NbtCompound` 

<br>

#### 往列表末尾追加一个NBT对象

`list.addTag(tag)`

- 参数：
  - tag: `NbtValue` 或 `NbtList` 或 `NbtCompound`  
    要追加的 NBT 对象（它承载着具体的NBT数据）  
- 返回值：追加完毕的NBT列表（便于连锁append）
- 返回值类型：`NbtList`

<br>

#### 将List类型转换为Array（方便函数）

`list.toArray()`

- 返回值：对应的数组 / 列表
- 返回值类型：`Array`

将List转换为LXL数组 / 列表，把所有能转换为LXL数据类型的数据项都转换为LXL数据类型储存于数组 / 列表的对应下标中，方便读取和处理  
如果List某一项储存的是`List`类型 NBT，将在对应位置放置一个`NbtList`对象；如果List某一项储存的是`Compound`类型 NBT，将在对应位置放置一个`NbtCompound`对象

<br>

#### 由Array读取并全部写入List类型（方便函数）

`list.fromArray(arr)`

- 参数：
  - arr: `Array`  
    要读取的数组 / 列表
- 返回值：是否成功转换
- 返回值类型：`Boolean`

由LXL数组 / 列表反向生成并写入list，上面一个函数的逆向操作