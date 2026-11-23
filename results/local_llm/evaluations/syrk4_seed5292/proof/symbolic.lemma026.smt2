; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x755 (bvmul arg0_11 arg0_12)))
(let ((?x37078 (bvmul (_ bv4294967295 32) ?x755)))
(let ((?x807 (bvmul arg0_11 arg0_3)))
(let ((?x30616 (bvadd ?x807 ?x37078)))
(and (distinct ?x30616 (_ bv0 32)) true))))))
(check-sat)
