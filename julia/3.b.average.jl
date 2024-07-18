function sumcountaverage()
    n=0
    sum=0
    print("enter a number: ")
    while(snum=readline()) !=""
        n +=1
        sum += parse(Int64, snum)
        print("enter a number: ")
    end
    if n==0
        println("\nNo numbers entered")
    else
        println("\n$n number(s) entered")
        println("sum is $sum")
        println("average is $(round(sum/n,digits=1))")
    end
end
sumcountaverage()