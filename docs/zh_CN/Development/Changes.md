# LiteXLoader - 重大更改页面

这里列出了LXL引擎对 **API** 进行的一些可能会造成 **不向下兼容** 的重大更改。  
如果你的插件在更新版本后发生问题，请首先查阅本章节的相关内容，检查是否由API变更导致。

#### 20210709 - v 0.0.7

- 删除注册自定义命令回调参数args中的第一个前缀项（即原来的args[0]）。  
  args数组从此只包含所注册的命令分割出的参数  
  具体详见命令系统API相关文档说明
- 将`IntPos`与`FloatPos`类型中的`dim`变量重命名为`dimid`，表意维度ID更加清晰

#### 20210713 - v 0.0.7

- `lxl.getVerion` 返回值类型变为`Object`
- `pl.sendSimpleForm` 函数增加 `images` 参数

#### 20210714 - v 0.0.7

- 将事件`onOpenChest`和`onOpenBarrel`合并为`onOpenContainer`
- 将事件`onCloseChest`和`onCloseBarrel`合并为`onCloseContainer`
- 将事件`onChangeSlot`重命名为`onContainerChangeSlot`
- 将接口`file.read`重命名为`file.readFrom`，将接口`file.write`重命名为`file.writeTo`
- 通用日志接口的 日志输出等级 发生了较大变化
- 将事件`onServerCmd`重命名为`onConsoleCmd`

#### 20210717 - v 0.0.8

- 适配 1.17.10
- 表单函数回调函数的参数内容发生较大变化