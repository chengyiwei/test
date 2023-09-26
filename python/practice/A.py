import turtle

# 创建画布
screen = turtle.Screen()
screen.bgcolor("skyblue")

# 创建太阳
sun = turtle.Turtle()
sun.shape("circle")
sun.color("yellow")
sun.shapesize(5)  # 调整太阳的大小

# 创建太阳的光芒
rays = turtle.Turtle()
rays.color("yellow")
rays.width(3)
for _ in range(12):
    rays.penup()
    rays.goto(0, 0)
    rays.pendown()
    rays.forward(100)
    rays.backward(100)
    rays.right(30)

# 隐藏海龟箭头
sun.hideturtle()
rays.hideturtle()

# 关闭窗口时退出
screen.exitonclick()
