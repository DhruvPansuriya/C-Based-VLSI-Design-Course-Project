; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_16 () (_ BitVec 32))
(assert
 (let ((?x75319 (bvmul arg0_2 arg1_2)))
(let ((?x64703 (bvmul (_ bv4294967295 32) ?x75319)))
(let ((?x17950 (bvmul arg0_2 arg1_16)))
(let ((?x65054 (bvadd ?x17950 ?x64703)))
(and (distinct ?x65054 (_ bv0 32)) true))))))
(check-sat)
