function lettersonlylower(phrase)
    word = ""
    for ch in phrase
        if isletter(ch)
            word *= lowercase(ch)
        end
end
return word
end
function ispalindrome(phrase)
    word=lettersonlylower(phrase)
    lo=1
    hi= length(word)
    while lo<hi
        if word[lo] != word[hi] return false end
        lo +=1; hi-= 1
    end
    return true
end
function Main()
    print("\nWord or phrase?(To stop, press enter): ")
    phrs= readline()
    while phrs != ""
        if ispalindrome(phrs)
            println("is a palindrome")
        else
            println("is not a palindrome")
    end
    print("\nWord or phrase?(To stop, press enter): ")
    phrs=readline()
end
end
main()