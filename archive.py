import os

class Problem:
    def __init__(self, id, title, acceptance, difficulty):
        self.id = int(id)
        self.title = title.strip()
        self.acceptance = acceptance
        self.difficulty = difficulty
        self.link = self.get_link()
    def get_link(self):
        signs = '()'
        prefix = 'https://leetcode.com/problems/'
        link = ''.join([c for c in self.title.lower() if c not in signs])
        link = prefix + link.replace(' ', '-').replace(',', '')
        return link

def difficulty2level(difficulty):
    c = difficulty[0].lower()
    if c == 'e':
        return 1
    elif c == 'm':
        return 2
    elif c == 'h':
        return 3
    return 0

def read_problems_list(fname):
    problems = {}
    with open(fname) as fin:
        fin.readline() # skip
        while 1:
            pid = fin.readline()
            if not pid:
                break
            pid = int(pid)
            info = fin.readline()
            sp = info.split()
            difficulty = sp[-1]
            acceptance = sp[-2]
            name = ' '.join(sp[:-2])
            problem = Problem(pid, name, acceptance, difficulty)
            problems[pid] = problem
    return problems

list_fname = './problems.lst'
problems = read_problems_list(list_fname)

TERMS = ['DFS', 'BFS']
TERMS_CAP = [s.capitalize() for s in TERMS]

def cap(s):
    s = s.capitalize()
    try:
        return TERMS[TERMS_CAP.index(s)]
    except:
        pass
    return s.capitalize()

def get_weekname(week):
    sp = week.split('_')
    assert sp[0].startswith('week')
    prefix = 'Week {} - '.format(sp[0][4:])
    week_name = prefix + ' '.join([cap(s) for s in sp[1:]])
    return week_name

def gen_readme_for_week(week):
    week_name = get_weekname(week)
    out = """## {}
Index|Title|Solution(s)|Acceptance|Difficulty
-|-|-|-|-
""".format(week_name)
    exts = dict([
        ('.cpp', 'C++'),
        ('.rs', 'Rust'),
    ])
    solved = dict()
    for fname in os.listdir(week):
        name, ext = os.path.splitext(fname)
        if ext in exts:
            code_type = exts[ext]
            try:
                si = name.index('.')
                pid = int(name[:si])
            except:
                try:
                    si = name.index('-')
                    pid = int(name[:si])
                except:
                    continue
            assert pid in problems, pid
            if pid not in solved:
                solved[pid] = set()
            solved[pid].add((code_type, fname))
    solved = list(solved.items())
    def key_for_solved(x):
        problem = problems[x[0]]
        acc = 100.0 - float(problem.acceptance[:-1])
        difficulty = difficulty2level(problem.difficulty)
        return difficulty * 100 + acc
    solved.sort(key=key_for_solved)
    spath = './'

    for pid, solutions in solved:
        problem = problems[pid]
        title = '[{}]({})'.format(
            problem.title,
            problem.link
        )
        solution = ', '.join([
            '[{}]({})'.format(code_type, os.path.join(spath, fname))
            for code_type, fname in solutions
        ])
        acceptance = problem.acceptance
        difficulty = problem.difficulty
        po = [pid, title, solution, acceptance, difficulty]
        out += '|'.join([str(s) for s in po])
        out += '\n'
    return out


def gen_readme():
    weeks = []
    for dirname in os.listdir('./'):
        if dirname.startswith('week'):
            weeks.append(dirname)
    weeks.sort(key=lambda x : -int(x[4:x.index('_')]))
    out = """# Weekly Challenge for Algorithm
Thanks [@shicheng0829](https://github.com/shicheng0829) for collecting these problems! It is really helpful :)

[@shicheng0829](https://github.com/shicheng0829) collected problems during week 1 and week 7.

[@wkcn](https://github.com/wkcn) collects problems since week 8.

## Topics
"""
    for week in weeks:
        out += "\n[{week_name}]({path})\n".format(week_name=get_weekname(week), path=os.path.join('./', week))
    for week in weeks:
        week_readme = gen_readme_for_week(week)
        with open(os.path.join(week, 'README.md'), 'w') as fout:
            fout.write(week_readme)
    return out


if __name__ == '__main__':
    out = gen_readme()
    with open('README.md', 'w') as fout:
        fout.write(out)
    print("Over")
