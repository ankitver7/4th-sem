import wikipedia
def search_and_return_info(query):
    try:
        wikipedia.set_lang("en")
        search_res=wikipedia.search(query)
        if not search_res:
            return "No result found. please try another search term."
        page_sum=wikipedia.summary(search_res[0],sentences=2)
        page_url=wikipedia.page(search_res[0]).url
        return f"Here's what I found :\n{page_sum}\n\n you can read more here:{page_url}"
    except wikipedia.exceptions.DisambiguationError as e:
        return f"Search term is ambiguous. Did you mean:{','.join(e.options[:5])}?"
    except wikipedia.exceptions.PageError:
        return f"No matching page found. Please try another search term."
search_term=input("Enter the search term:")
res=search_and_return_info(search_term)
print(res)