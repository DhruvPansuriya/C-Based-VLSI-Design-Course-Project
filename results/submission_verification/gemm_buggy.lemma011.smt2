; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x203 (bvmul arg0_1 arg1_13)))
(let ((?x20881 (bvmul (_ bv4294967295 32) ?x203)))
(let ((?x12 (bvmul arg0_1 arg1_7)))
(let ((?x16715 (bvadd ?x12 ?x20881)))
(and (distinct ?x16715 (_ bv0 32)) true))))))
(check-sat)
