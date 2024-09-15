# Từ điển cơ bản cho các số và hàng đơn vị
so_tu_1_den_9 = ["", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"]
hang_don_vi = ["", "nghìn", "triệu", "tỷ"]

# Hàm đọc 3 chữ số
def doc_ba_chu_so(so):
    tram = so // 100
    chuc = (so % 100) // 10
    don_vi = so % 10
    ket_qua = ""
    
    if tram > 0:
        ket_qua += so_tu_1_den_9[tram] + " trăm "
        if chuc == 0 and don_vi > 0:
            ket_qua += "lẻ "
    
    if chuc > 1:
        ket_qua += so_tu_1_den_9[chuc] + " mươi "
        if don_vi == 1:
            ket_qua += "mốt "
        elif don_vi == 5:
            ket_qua += "lăm "
        else:
            ket_qua += so_tu_1_den_9[don_vi]
    elif chuc == 1:
        ket_qua += "mười "
        if don_vi == 5:
            ket_qua += "lăm"
        else:
            ket_qua += so_tu_1_den_9[don_vi]
    elif don_vi > 0:
        ket_qua += so_tu_1_den_9[don_vi]
    
    return ket_qua.strip()

# Hàm đọc số nguyên
def doc_so(so):
    if so == 0:
        return "không"
    
    ket_qua = ""
    index_hang_don_vi = 0

    while so > 0:
        ba_chu_so = so % 1000
        if ba_chu_so > 0:
            ket_qua = doc_ba_chu_so(ba_chu_so) + " " + hang_don_vi[index_hang_don_vi] + " " + ket_qua
        so //= 1000
        index_hang_don_vi += 1

    return ket_qua.strip()

# Hàm chính
def doc_so_tieng_viet(so):
    if len(str(so)) > 15:
        return "Số nhập vào quá dài, vui lòng nhập số tối đa 15 chữ số."
    try:
        so = int(so)
        return doc_so(so)
    except ValueError:
        return "Đầu vào không hợp lệ, vui lòng nhập một số nguyên."

# Ví dụ
so = input("Nhập số (tối đa 15 chữ số): ")
print(doc_so_tieng_viet(so))
