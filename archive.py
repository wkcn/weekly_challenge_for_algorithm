import os
from tqdm import tqdm

EXTS = dict([
    ('.cpp', 'C++'),
    ('.rs', 'Rust'),
])

class Problem:
    def __init__(self, id, title, acceptance, difficulty):
        self.id = int(id)
        self.title = title.strip()
        self.acceptance = acceptance
        self.difficulty = difficulty
        self.link = self.get_link()
        self.path = ""
        self.solutions = []
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

def get_problem_id(name):
    try:
        si = name.index('.')
        pid = int(name[:si])
        return pid
    except:
        try:
            si = name.index('-')
            pid = int(name[:si])
            return pid
        except:
            pass
    return None


list_fname = './problems.lst'
PROBLEM_LIST = read_problems_list(list_fname)


def get_finished_problems():
    weeks = []
    for dirname in os.listdir('./'):
        if dirname.startswith('week'):
            weeks.append(dirname)
    weeks.sort(key=lambda x : -int(x[4:x.index('_')]))
    problems = set()
    for week in weeks:
        for fname in os.listdir(week):
            name, ext = os.path.splitext(fname)
            if ext in EXTS:
                pid = get_problem_id(fname)
                if pid is not None:
                    problems.add(pid)
    problems = list(problems)
    return problems


FINISHED_PROBLEMS = get_finished_problems()


def write_all_problems():
    with open('problems.md', 'w') as fout:
        fout.write("""## Problems
Done|Title|Solution(s)|Difficulty|Topic
-|-|-|-|-
""")
        for p in PROBLEM_LIST.values():
            flag = '✔' if p.id in FINISHED_PROBLEMS else '-'

            solutions = ', '.join([
                f'[{code_type}]({os.path.join(p.path, fname)})'
                for code_type, fname in p.solutions
            ])
            msg = f'{flag}|[{p.id}.{p.title}]({p.link})|{solutions}|{p.difficulty}|'
            if p.path:
                msg += f'[{p.path}]({p.path})'
            # Add Code
            fout.write(msg + '\n')


TERMS = ['DFS', 'BFS']
TERMS_CAP = dict((s.capitalize(), s) for s in TERMS)

def cap(s):
    s = s.capitalize()
    for cap in TERMS_CAP:
        if s.startswith(cap):
            return TERMS_CAP[cap] + s[len(cap):]
    return s

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
    solved = dict()
    for fname in os.listdir(week):
        name, ext = os.path.splitext(fname)
        if ext in EXTS:
            code_type = EXTS[ext]
            pid = get_problem_id(name)
            if pid is None:
                continue
            assert pid in PROBLEM_LIST, pid
            if pid not in solved:
                solved[pid] = list()
            solved[pid].append((code_type, fname))
    for pid in solved.keys():
        solved[pid].sort()
        # assert len(PROBLEM_LIST[pid].solutions) == 0, (week, pid)
        PROBLEM_LIST[pid].solutions = solved[pid]
        PROBLEM_LIST[pid].path = week
    solved = list(solved.items()) # a list of (pid, (code_type, fname))
    def key_for_solved(x):
        problem = PROBLEM_LIST[x[0]]
        acc = 100.0 - float(problem.acceptance[:-1])
        difficulty = difficulty2level(problem.difficulty)
        return difficulty * 100 + acc
    solved.sort(key=key_for_solved)
    spath = './'

    for pid, solutions in solved:
        problem = PROBLEM_LIST[pid]
        title = f'[{problem.title}]({problem.link})'
        solution = ', '.join([
            f'[{code_type}]({os.path.join(spath, fname)})'
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
    n = len(FINISHED_PROBLEMS)
    total = len(PROBLEM_LIST)
    elapsed = len(weeks) * 7 * 24 * 60 * 60
    progress = tqdm.format_meter(n, total, elapsed, ncols=100)
    out = """# Weekly Challenge for Algorithm
Thanks [@shicheng0829](https://github.com/shicheng0829), [@wkcn](https://github.com/wkcn), [@somainer](https://github.com/somainer) for collecting these problems! It is really helpful :)

[@shicheng0829](https://github.com/shicheng0829) collected problems during week 1 and week 7.

[@wkcn](https://github.com/wkcn) collected problems during week 8 and week 18.

[@somainer](https://github.com/somainer) collects problems since week 19.

## Progress
```
{progress}
```
[[Problem List]](./problems.md)

## Topics
""".format(progress=progress)
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
    write_all_problems()
    print("Over")
