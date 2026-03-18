# ĐỒ ÁN 1: XV6 – UNIX UTILITIES & SYSTEM CALL

## 1. Thông tin chung
- **Môn học:** Hệ điều hành  
- **Trường:** Đại học Khoa học Tự nhiên – ĐHQG HCM  

Đồ án tập trung mở rộng hệ điều hành **xv6** thông qua:
- Xây dựng chương trình ở **User-space**
- Cài đặt **System Call** trong **Kernel-space**

---

## 2. Thành viên nhóm

| STT | Họ và tên | MSSV | Công việc | Hoàn thành |
|:--:|:--|:--:|:--|:--:|
| 1 | Hồ Thị Như Ngọc | 24127089 | `procinfo`, báo cáo | 100% |
| 2 | Phan Đình Minh Quân | 24127517 | `xargs`, `tree` | 100% |
| 3 | Lê Thị Như Ý | 24127595 | `trace`, GitHub | 100% |

---

## 3. Chức năng chính đã cài đặt

###  User Programs
- **`xargs`**: Đọc input từ stdin và truyền làm tham số cho lệnh khác (`fork`, `exec`)
- **`tree`**: Hiển thị cấu trúc thư mục dạng cây (đệ quy, dùng heap tránh tràn stack)

###  System Calls
- **`trace (22)`**: Theo dõi system call bằng bitmask, kế thừa qua `fork()`, O(1)
- **`procinfo (23)`**: Lấy thông tin tiến trình (PID, PPID, State, Memory, Name)

---

## 4. Hướng dẫn Cài đặt & Môi trường

Để biên dịch và chạy XV6, bạn cần chuẩn bị môi trường trên Ubuntu.

**Bước 1: Cài đặt các công cụ cần thiết**
Mở terminal và chạy các lệnh sau:
```bash
sudo apt update
sudo apt install build-essential
sudo apt install gcc-riscv64-linux-gnu
sudo apt install binutils-riscv64-linux-gnu
sudo apt install qemu-system-misc
```

**Bước 2: Lấy source code XV6**
Clone repository chứa mã nguồn đồ án của nhóm:
```bash
git clone https://github.com/ltny24/Project-1-Xv6-Unix-Utilities-and-System-Call.git
cd Project-1-Xv6-Unix-Utilities-and-System-Call
```

---

## 5. Biên dịch & Khởi chạy

Để dọn dẹp các file build cũ và biên dịch lại hệ điều hành xv6, sử dụng lệnh:

```bash
make clean
make qemu
```

Hệ điều hành xv6 sẽ khởi động bên trong trình giả lập QEMU.

---

## 6. Hướng dẫn Test các chức năng

Sau khi xv6 đã khởi động thành công và hiển thị dấu nhắc lệnh `$`, bạn có thể kiểm thử các chức năng bằng các lệnh sau:

### Kiểm thử `xargs`
```bash
echo hello too | xargs echo bye
```

### Kiểm thử `tree`
```bash
tree .
tree a
```

### Kiểm thử `trace`
```bash
trace 32 grep hello README
trace 2147483647 grep hello README
trace 2 usertests forkforkfork
```

### Kiểm thử `procinfo`
Chạy chương trình test đã được viết sẵn:
```bash
test_procinfo
```

---

## 7. Tài liệu tham khảo
- Sách xv6 (xv6 Book).
- Tài liệu lý thuyết và thực hành môn học (Moodle).
- Hướng dẫn: "HOW TO ADD A NEW SYSTEM CALL".

---

## 8. Kết luận
Qua đồ án này, nhóm đã:
- Hiểu sâu hơn về cơ chế hoạt động của System Call.
- Làm quen và trực tiếp thao tác với mã nguồn Kernel của xv6.
- Nâng cao tư duy và kỹ năng lập trình hệ thống (C/C++), quản lý bộ nhớ và tiến trình.
```
