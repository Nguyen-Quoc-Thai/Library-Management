# Library-Management

Console GUI

Quản lí thư viện trên cơ sở dữ liệu File.

Chức năng:

	+ Thêm, xóa, chỉnh sữa, tìm kiếm sách qua (id, name, author, publisher, price)
	
	+ Thêm, xóa, chỉnh sữa, tìm kiếm đọc giả qua (id, name, author, publisher, price)
	
	+ In phiếu mượn sách theo ID (File)
	
	+ In phiếu trả sách theo ID (File)
	
	+ In tất cả các phiếu mượn sách (File)
	
	+ In tất cả các phiếu trả sách (File)
	
	+ In danh sách các đọc giả quá hạn mượn sách cùng thông tin chi tiết và tổng số tiền phạt (Console và File)
	
	
Mô tả sơ lược chương trình:

	- Khi chạy chương trình: chương trình sẽ tự động load file các Sách trong thư viện và file các Đọc giả mượn sách đã lưu ở phiên làm việc trước lên
	
	- Tiếp theo, người dùng có thể thao tác xữ lý với Menu trên.
	
		+ Khi thêm sách, ta nhập lần lượt các thông tin theo yêu cầu.
		
		+ Khi xóa, sửa, tìm kiếm sách ta có thể lọc theo các tùy chọn (id, name, author, publisher, price)
		
		+ Khi thêm đọc giả, ta nhập lần lượt các thông tin theo yêu cầu (Bao gồm ID và Tên đọc giả, và một Arr các quyển sách sách đã mượn). Khi nhập ngày mượn sách có 2 tùy chọn 
		
			[1. Lấy ngày giờ hiện tại của hệ thống, 2. Nhập bằng tay theo định dạng (dd/mm/yyyy) (Có kiểm tra định dạng và ngày tháng hợp hệ)]. Khi nhập các quyển sách sắp mượn 
			
			ta chỉ cần nhập Book_id. Nếu sách đã có trong thư viện sách rồi thì hệ thống sẽ tự động thêm vào mảng các quyển sách sắp mượn, nếu chưa có thì hệ thống sẽ thông báo
			
			và yêu cầu người dùng nhập thông tin sách đó đồng thời thêm quyển sách đó vào cả mảng và thư viện.
			
		+ Khi xóa, sửa, tìm kiếm sách ta có thể lọc theo các tùy chọn (id, name, author, publisher, price)
		
		+ In phiếu mượn sách trả sách ta cần truyền vào ID của đọc giả (In ở Folder mượn, trả)
		
		+ In tất cả các phiếu mượn sách trả sách (In ở Folder tất cả mượn, trả)
		
		+ In danh sách các đọc giả quá hạn mượn sách cùng thông tin chi tiết và tổng số tiền phạt (In ở Folder Overdue)
	
	- Khi thoát chương trình, phiên làm việc hiện tại sẽ được lưu xuống file.
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	