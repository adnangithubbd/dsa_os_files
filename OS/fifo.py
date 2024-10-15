def fifo_page_replacement(pages,capacity):
    memory=[]
    page_fault=0
    
    for page in pages:
        if page not in memory:
            if len(memory)<capacity:
                memory.append(page)
            else:
                memory.pop(0)
                memory.append(page)
            page_fault+=1
        print(f"Memory {memory}")
    return page_fault


pages = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]
capacity = 3 
res=fifo_page_replacement(pages,capacity)
print(res)