class Free_block_area:
    def __init__(self, start_block=0, end_block=63):
        self.start_block = start_block
        self.end_block = end_block
        self.size = self.end_block - self.start_block + 1


class RAM:
    def __init__(self):
        self.map = [0 for i in range(64)]
        self.page_table = []
        self.max_free_block = 64
        self.free_block_list = []
        self.free_block_list.append(Free_block_area())

    def allocate(self, n_blocks):
        if n_blocks > self.max_free_block or n_blocks < 0:
            return False
        for item in self.free_block_list:
            if n_blocks < item.size:
                self.allocate_map(item.start_block, item.start_block + n_blocks - 1)
                self.add_page_table(item.start_block, n_blocks)
                item.start_block = item.start_block + n_blocks
                item.size = item.size - n_blocks
            if n_blocks == item.size:
                self.allocate_map(item.start_block, item.end_block)
                self.add_page_table(item.start_block, item.size)
                self.free_block_list.remove(item)

    def free(self, page_table_index):
        page_item = self.page_table.pop(page_table_index)
        start = page_item['start_block']
        end = start + page_item['n_blocks'] - 1
        if start == 0:
            if self.map[end + 1] == 0:
                block = self.find_start_block(end + 1)
                block.start_block = start
                block.size = block.size + page_item['n_blocks']
                self.free_map(start, end)
                return
            else:
                self.free_map(start, end)
                self.free_block_list.append(Free_block_area(start, end))
                return
        if end == 63:
            if self.map[start - 1] == 0:
                block = self.find_end_block(start - 1)
                block.end_block = end
                block.size = block.size + page_item['n_blocks']
                self.free_map(start, end)
                return
            else:
                self.free_map(start, end)
                self.free_block_list.append(Free_block_area(start, end))
                return
        if self.map[start - 1] == 0:
            block = self.find_end_block(start - 1)
            block.end_block = end
            block.size = block.size + page_item['n_blocks']
            self.free_map(start, end)
            return
        if self.map[end + 1] == 0:
            block = self.find_start_block(end + 1)
            block.start_block = start
            block.size = block.size + page_item['n_blocks']
            self.free_map(start, end)
            return
        self.free_block_list.append(Free_block_area(start, end))

    def allocate_map(self, start, end):
        for i in range(start, end + 1):
            self.map[i] = 1

    def free_map(self, start, end):
        for i in range(start, end + 1):
            self.map[i] = 0

    def add_page_table(self, start, n_blocks):
        self.page_table.append({'start_block': start, 'n_blocks': n_blocks})

    def print_table(self):
        for index, item in enumerate(self.page_table):
            print("table index:{},start block:{},n_blocks:{}".format(index, item['start_block'], item['n_blocks']))

    def print_map(self):
        for i in range(8):
            for j in range(1, 9):
                print(self.map[8 * i + j - 1], end=" ")
            print("")

    def find_start_block(self, start_block):
        for item in self.free_block_list:
            if item.start_block == start_block:
                return item

    def find_end_block(self, end_block):
        for item in self.free_block_list:
            if item.end_block == end_block:
                return item


class OS_Env:
    def __init__(self):
        self.ram = RAM()

    def run(self):
        self.ram.allocate(3)
        self.ram.allocate(10)
        self.ram.print_map()
        self.ram.print_table()
        self.ram.free(1)
        self.ram.print_map()
        self.ram.print_table()

    def run_loop(self):
        print("input command like assign 10 ,print map, print table")
        flag = True
        while (flag):
            para_string = input("please input command:")
            para_list = para_string.split(' ')
            if para_list[0] == "assign":
                self.ram.allocate(int(para_list[1]))
            if para_list[0] == "release":
                self.ram.free(int(para_list[1]))
            if para_list[0] == "print":
                if para_list[1] == "map":
                    self.ram.print_map()
                elif para_list[1] == "table":
                    self.ram.print_table()
                else:
                    print("Wrong parameter please input again!")
            if para_list[0] == "exit":
                flag = False


if __name__ == '__main__':
    os = OS_Env()
    os.run()
    os.run_loop()