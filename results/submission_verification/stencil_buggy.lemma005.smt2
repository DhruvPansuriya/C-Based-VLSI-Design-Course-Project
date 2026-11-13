; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x1142 (bvmul arg0_2 arg2_2)))
(let ((?x126 (bvmul (_ bv4294967295 32) ?x1142)))
(let ((?x182 (bvmul arg0_2 arg2_1)))
(let ((?x714402 (bvadd ?x182 ?x126)))
(and (distinct ?x714402 (_ bv0 32)) true))))))
(check-sat)
