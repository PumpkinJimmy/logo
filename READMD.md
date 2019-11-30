### 简化版logo解释器
目前支持的特性：
- DEF *var* *value* 定义变量，变量名开头不能为数字，数字只能是整数
- ADD *var* *value* 增加变量值，value可以是任意整数
- MOVE *distance* Turtle移动
- TURN *degree* 转若干角度
- COLOR *r* *g* *b* 设置颜色，同时解除隐身
- CLOAK 隐身
- PRINT *var* 输出变量值，调试用
- LOOP *cnt* 计数循环
- END LOOP 结束循环体
- FUNC foo(a,b,...) 定义函数
- END FUNC 结束函数定义
- CALL foo(a,b,...) 调用函数
