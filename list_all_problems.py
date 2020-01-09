import os
from archive import problems as problems_list 
exts = dict([
    ('.cpp', 'C++')
])
def get_all_problems():
    weeks = []
    for dirname in os.listdir('./'):
        if dirname.startswith('week'):
            weeks.append(dirname)
    weeks.sort(key=lambda x : -int(x[4:x.index('_')]))
    problems = []
    for week in weeks:
        for fname in os.listdir(week):
            name, ext = os.path.splitext(fname)
            if ext in exts:
                problems.append(int(fname[:fname.index('.')]))
    problems.sort()
    return problems

if __name__ == '__main__':
    finished = get_all_problems()
    with open('done.md', 'w') as fout:
        for p in problems_list.values():
            flag = 'x' if p.id in finished else ' ' 
            fout.write(f'- [{flag}] {p.id}.{p.title}\n')
