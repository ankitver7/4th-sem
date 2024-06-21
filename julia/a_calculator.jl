function display_menu()
    println("welcome to the Calculator Program")
    println("1. Addition")
    println("2. Subtraction")
    println("3. Multiplication")
    println("4. Division")
    println("5. Exit")
    println("Enter your choice(1-5): ")
end
function addition(a,b)
    return a+b
end
function subtraction(a,b)
    return a-b
end
function multiplication(a,b)
    return a*b
end
function division(a,b)
    if b != 0
        return a/b
    else
        println("Error: Division by zero!")
        return NaN
    end
end
#main function
function main()
    while true
display_menu()
    choice = parse(Int64, readline())
    if choice==5
        println("Exiting Calculator Program.")
        break
    end
println("Enter first number: ")
num1=parse(Float64, readline())
println("Enter second number: ")
num2=parse(Float64, readline())
if choice == 1
    result=addition(num1, num2)
    println("result: ", result)
elseif choice == 2
    result = subtraction(num1, num2)
    println("result: ", result)
elseif choice == 3
    result = multiplication(num1, num2)
    println("result: ", result)
elseif choice == 4
    result = division(num1, num2)
    println("result: ", result)
else
    println("Invalid choice! please enter a number between 1 and 5")
end
end 
end
main()