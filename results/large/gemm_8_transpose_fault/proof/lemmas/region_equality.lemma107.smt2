; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_59 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_31 () (_ BitVec 32))
(assert
 (let ((?x39419 (bvmul arg0_11 arg1_59)))
(let ((?x35236 (bvmul (_ bv4294967295 32) ?x39419)))
(let ((?x63384 (bvmul arg0_11 arg1_31)))
(let ((?x34194 (bvadd ?x63384 ?x35236)))
(and (distinct ?x34194 (_ bv0 32)) true))))))
(check-sat)
