class Table:
    def __init__(self):
        self.table = []

    def add_entry(self, start_block, block_number, status):
        self.table.append({'start_block': start_block, 'block_number': block_number, 'status': status})
        self.table.sort(key=lambda x: x['start_block'])
        for index, entry in enumerate(self.table):
            if index + 1 < len(self.table) and entry['start_block'] + entry['block_number'] == self.table[index + 1][
                'start_block']:
                self.table[index]['block_number'] += self.table[index + 1]['block_number']
                self.table.remove(self.table[index + 1])

    def check(self, block_number):
        for index, entry in enumerate(self.table):
            start_block = entry['start_block']
            if entry['block_number'] > block_number and entry['status']:
                self.table[index]['block_number'] -= block_number
                self.table[index]['start_block'] += block_number
                return start_block
            elif entry['block_number'] == block_number and entry['status']:
                self.table.remove(entry)
                return start_block
            else:
                return None

    def printer(self):
        for index, entry in enumerate(self.table):
            print(entry)
        # print(str(index+1),'----',str(entry['start_block']),'-----',str(entry['block_number']))


class DiskSimulator:
    def __init__(self, cylinder, track, sector):
        self.cylinder = cylinder
        self.track = track
        self.sector = sector
        self.table = []
        self.last_cylinder = 0
        self.last_track = 0
        self.last_sector = 0

    def block_to_address(self, block):
        sector = block % self.sector
        track = int(block / self.sector) % self.track
        cylinder = int(int(block / self.sector) / self.track)
        return [cylinder, track, sector]

    def address_to_block(self, cylinder, track, sector):
        block = (cylinder * self.track + track) * self.sector + sector
        return block

    def add_entry(self, cylinder, track, sector, sector_number):
        self.table.append({'cylinder': cylinder, 'track': track, 'sector': sector, 'sector_number': sector_number})
        self.table.sort(key=lambda x: (x['cylinder'], x['track'], x['sector']))

    def assign(self, start_block, block_number):
        start_cylinder, start_track, start_sector = self.block_to_address(start_block)
        self.add_entry(start_cylinder, start_track, start_sector, block_number)

    def default_assign(self, block_number):
        cylinder, track, sector = self.block_to_address(block_number)
        self.add_entry(self.last_cylinder, self.last_track, self.last_sector, block_number)
        self.last_sector += sector
        if self.last_sector >= self.sector:
            self.last_sector -= self.sector
            self.last_track += 1
        self.last_track += track
        if self.last_track >= self.track:
            self.last_track -= self.track
            self.last_cylinder += 1
        self.last_cylinder += cylinder

    def release(self, index):
        if index - 1 >= len(self.table):
            return []
        entry = self.table[index - 1]
        start_block = self.address_to_block(entry['cylinder'], entry['track'], entry['sector'])
        block_number = entry['sector_number']
        self.table.remove(entry)
        return [start_block, block_number]

    def printer(self):
        for index, entry in enumerate(self.table):
            print(entry)


class Disk:
    def __init__(self, cylinder, track, sector):
        self.cylinder = cylinder
        self.track = track
        self.sector = sector
        self.table = Table()
        self.disksimulator = DiskSimulator(cylinder, track, sector)

    def assgin(self, block):
        start_block = self.table.check(block)
        if start_block is not None:
            # start_block = self.table.check(block)
            self.disksimulator.assign(start_block, block)
        else:
            self.disksimulator.default_assign(block)

    def release(self, index):
        start_block, block_number = self.disksimulator.release(index)
        self.table.add_entry(start_block, block_number, 1)

    def print_disk(self):
        self.disksimulator.printer()

    def print_table(self):
        self.table.printer()


class RunEnviroment:
    def __init__(self):
        self.disk = Disk(200, 20, 6)
        self.disk.assgin(23000)
        self.disk.assgin(500)
        self.disk.assgin(200)
        self.disk.assgin(300)

        # disk.print_disk()
        self.disk.release(1)
        # disk.print_table()
        self.disk.release(1)
        self.disk.assgin(500)
        self.disk.print_disk()
        self.disk.print_table()

    def run(self):
        for i in range(100):
            cmd = input("输入命令:形如assign 10,print table   ")
            cmd_list = cmd.split(' ')
            if cmd_list[0] == "assign":

                self.disk.assgin(int(cmd_list[1]))
            if cmd_list[0]== "release":

                self.disk.release(int(cmd_list[1]))
            if cmd_list[0] == "print":
                if cmd_list[1] == "disk":
                    self.disk.print_disk()
                elif cmd_list[1] == "table":
                    self.disk.print_table()
                else:
                    print("Wrong parameter please input again!")



if __name__ == '__main__':
    run = RunEnviroment()
    run.run()
