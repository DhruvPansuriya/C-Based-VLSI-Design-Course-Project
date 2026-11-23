; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x142 (bvmul arg0_1 arg1_13)))
(let ((?x13255 (bvmul (_ bv4294967295 32) ?x142)))
(let ((?x68 (bvmul arg0_1 arg1_7)))
(let ((?x20387 (bvadd ?x68 ?x13255)))
(and (distinct ?x20387 (_ bv0 32)) true))))))
(check-sat)
