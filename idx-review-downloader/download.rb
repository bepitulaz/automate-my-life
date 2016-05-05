require "csv"

CSV.foreach("stock-code.csv") do |row|
  company_code = row[0]
  url = "http://www.idx.co.id/Portals/0/StaticData/ListedCompanies/PerformanceSummary/#{company_code}.pdf"
  %x|wget -c "#{url}" -O "pdf/#{company_code}.pdf"|
end
