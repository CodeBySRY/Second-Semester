# Second Semester

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
