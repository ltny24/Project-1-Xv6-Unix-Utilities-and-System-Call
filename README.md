# ĐỒ ÁN 1: XV6 – UNIX UTILITIES & SYSTEM CALL

## Thông tin chung
- **Môn học:** Hệ điều hành  
- **Trường:** Đại học Khoa học Tự nhiên – ĐHQG HCM  

Đồ án tập trung mở rộng hệ điều hành **xv6** thông qua:
- Xây dựng chương trình ở **User-space**
- Cài đặt **System Call** trong **Kernel-space**

---

## Thành viên nhóm

| STT | Họ và tên | MSSV | Công việc | Hoàn thành |
|:--:|:--|:--:|:--|:--:|
| 1 | Hồ Thị Như Ngọc | 24127089 | `procinfo`, báo cáo | 100% |
| 2 | Phan Đình Minh Quân | 24127517 | `xargs`, `tree` | 100% |
| 3 | Lê Thị Như Ý | 24127595 | `trace`, GitHub | 100% |

---

##  Chức năng chính

###  User Programs
- **`xargs`**: Đọc input từ stdin và truyền làm tham số cho lệnh khác (`fork`, `exec`)
- **`tree`**: Hiển thị cấu trúc thư mục dạng cây (đệ quy, dùng heap tránh tràn stack)

###  System Calls
- **`trace (22)`**: Theo dõi system call bằng bitmask, kế thừa qua `fork()`, O(1)
- **`procinfo (23)`**: Lấy thông tin tiến trình (PID, PPID, State, Memory, Name)

---

##  Build & Run

```bash
make clean
make qemu
```

---

##  Test

### xargs
```bash
echo hello too | xargs echo bye
```

### tree
```bash
tree .
tree a
```

### trace
```bash
trace 32 grep hello README
trace 2147483647 grep hello README
trace 2 usertests forkforkfork
```

### procinfo
```bash
test_procinfo
```

---

## Tài liệu
- xv6 Book  
- Tài liệu môn học (Moodle)  
- HOW TO ADD A NEW SYSTEM CALL  

---

## Kết luận
- Hiểu cơ chế System Call  
- Làm việc với Kernel xv6  
- Nâng cao kỹ năng lập trình hệ thống
