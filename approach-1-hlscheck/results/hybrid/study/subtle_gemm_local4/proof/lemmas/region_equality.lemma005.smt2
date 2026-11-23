; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x431677 (bvmul arg0_4 arg1_2)))
(let ((?x497880 (bvmul (_ bv4294967295 32) ?x431677)))
(let ((?x279424 (bvmul arg0_4 arg1_3)))
(let ((?x473231 (bvadd ?x279424 ?x497880)))
(and (distinct ?x473231 (_ bv0 32)) true))))))
(check-sat)
