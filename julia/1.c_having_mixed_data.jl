function evaluate_expression(expression)
    try
        result=Meta.parse(expression)
        println("Result: ", eval(result))
    catch e
        println("Error:", e)
    end
end

#main function
function main()
    println("Enter the expression to evaluate:")
    expression=readline()
    evaluate_expression(expression)
end

main()