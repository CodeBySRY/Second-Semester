# Second Semester
## 📚 Academic Courses

| Course Code | Course Name | Credit Hours | Lab Course |
| :---------- | :---------- | :----------- | :--------- |
| CS112       | Object Oriented Programming and Design | 2 | ✅ |
| ES111       | Probability and Statistics | 3 | |
| HM102       | Critical Thinking and Expository Writing | 2 | ✅ |
| MM101       | Materials and Nanotechnology | 2 | ✅ |
| MT102       | Differential Equations and Linear Algebra I | 3 | |
| IF102L      | Innovation and Makers Lab II | 1 | ✅ |

- Each lab course is **1 credit hour**.
---


> [!IMPORTANT]
> If you miss a single Innovation and Makers Lab (`IF102L`), your grade can drop drastically. The performance averages in these labs are extremely high, so it is crucial to take them seriously from the very beginning.

---
## 🧩 Miscellaneous
### 🛠️ Removing .exe Files from Git Repos (After Adding `.gitignore`)
If .exe files are still appearing in your GitHub repo even after adding *.exe to your .gitignore, it's because:

⚠️` Git tracks files that were already committed before .gitignore was added.`

The solution is to untrack already committed `.exe` files.
1. **Add** the rule to .gitignore *if not already present*:
```bash
*.exe
```
2. **Untrack** all .exe files (without deleting them locally):
```bash
git rm --cached -r *.exe
```
3. **Commit** the change:
```bash
git commit -m "Remove tracked .exe files and update .gitignore"
```
4. **Push** to the repository:
```bash
git push origin
```
---
