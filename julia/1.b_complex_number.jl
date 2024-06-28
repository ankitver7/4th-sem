struct complexnumber
    real::Float64
    imag::Float64
end

function add_complex(a::complexnumber,b::complexnumber)
    return complexnumber(a.real + b.real, a.imag + b.imag)
end

function subtract_complex(a::complexnumber,b::complexnumber)
    return complexnumber(a.real - b.real, a.imag - b.imag)
end

function multiply_complex(a::complexnumber,b::complexnumber)
real_part= a.real*b.real-a.imag*b.imag 
imag_part= a.real*b.imag-a.imag*b.real
    return complexnumber(real_part, imag_part)
end

function divide_complex(a::complexnumber,b::complexnumber)
    denominator=b.real^2+b.imag^2
    if denominator !=0
real_part= (a.real*b.real+a.imag*b.imag)/ denominator
imag_part= (a.real*b.imag-a.imag*b.real)/ denominator
        return complexnumber(real_part, imag_part)
    else
        print("Error: division by zero!")
        return complexnumber(NaN, NaN)
    end
end

#main function
function main()
    println("Enter the real and imaginary parts of the first complex number:")
    real1=parse(Float64, readline())
    imag1=parse(Float64, readline())
    println("Enter the real and imaginary parts of the second complex number:")
    real2=parse(Float64, readline())
    imag2=parse(Float64, readline())

    complex1=complexnumber(real1,imag1)
    complex2=complexnumber(real2,imag2)
    println("Addition:", add_complex(complex1, complex2))
    println("Subtraction:", subtract_complex(complex1, complex2))
    println("Multiplication:", multiply_complex(complex1, complex2))
    println("Division:", divide_complex(complex1, complex2))
end

main()