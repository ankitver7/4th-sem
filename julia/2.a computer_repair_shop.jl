using Printf
function jobchange()
    print("Hours worked? ")
    hours=parse(Float64,readline())
    print("cost of parts? ")
    parts=parse(Float64, readline())
    jobcharge=hours*100+parts
    if jobcharge<150
        jobcharge=150
end
@printf("\nTotal charges: \$%0.2f\n", jobcharge)
end
jobchange()