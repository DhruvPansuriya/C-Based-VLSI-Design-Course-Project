; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x147 (bvmul arg0_5 arg1_1)))
(let ((?x13166 (bvmul (_ bv4294967295 32) ?x147)))
(let ((?x82 (bvmul arg0_5 arg1_4)))
(let ((?x11042 (bvadd ?x82 ?x13166)))
(and (distinct ?x11042 (_ bv0 32)) true))))))
(check-sat)
